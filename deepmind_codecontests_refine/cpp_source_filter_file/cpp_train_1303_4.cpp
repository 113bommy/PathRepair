#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long inf = 1e9 + 5;
int n, m, a[maxn], b[maxn], nxt[maxn], prv[maxn];
long long gt, ct[maxn];
pair<int, int> sa[maxn];
set<pair<long long, int> > cross;
long long up(long long x) { return x + (n - x % n) % n; }
long long down(long long x) { return x - x % n; }
int pos(int idx, long long p, long long v, long long t) {
  long long ret = p + t / n * v;
  if (idx < t % n) {
    ret += v;
  }
  return ret;
}
long long time(int x) {
  long long px = a[x], vx = b[x];
  int y = nxt[x];
  long long py = a[y], vy = b[y];
  long long dx = pos(x, px, vx, gt);
  long long dy = pos(y, py, vy, gt);
  if (dy <= dx) {
    py += (dx - dy) + (m - (dx - dy) % m) % m;
  }
  if (vx <= vy) {
    if (x < gt % n) {
      if (pos(y, py, vy, up(gt) + x + 1) <= pos(x, px, vx, up(gt) + x + 1)) {
        return up(gt) + x + 1;
      }
    } else {
      if (pos(y, py, vy, down(gt) + x + 1) <=
          pos(x, px, vx, down(gt) + x + 1)) {
        return down(gt) + x + 1;
      }
    }
    return n * inf;
  }
  long long lo, hi = n * inf / (vx - vy) + 10;
  if (x < gt % n) {
    lo = up(gt) + x + 1;
  } else {
    lo = down(gt) + x + 1;
  }
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    long long cur;
    if (x < mid % n) {
      cur = down(mid) + x + 1;
    } else {
      cur = down(mid) - n + x + 1;
    }
    if (pos(y, py, vy, cur) <= pos(x, px, vx, cur)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}
void erase(int x) {
  cross.erase({ct[x], x});
  nxt[prv[x]] = nxt[x];
  prv[nxt[x]] = prv[x];
}
int dist(int x, int y) { return (y - x + m) % m; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    --a[i];
    sa[i] = {a[i], i};
  }
  sort(sa, sa + n);
  for (int i = 0; i < n; i++) {
    nxt[sa[i].second] = sa[(i + 1) % n].second;
    prv[sa[(i + 1) % n].second] = sa[i].second;
  }
  for (int i = 0; i < n; i++) {
    ct[i] = time(i);
    cross.insert({ct[i], i});
  }
  while (cross.size() > 1 && cross.begin()->first < n * inf) {
    long long t = cross.begin()->first;
    int x = cross.begin()->second;
    int px = pos(x, a[x], b[x], t - 1) % m;
    int cnt = 0;
    while (1) {
      int y = nxt[x];
      if (x == y) {
        break;
      } else {
        int py = pos(y, a[y], b[y], t - 1) % m;
        if (dist(px, py) <= b[x]) {
          erase(y);
          ++cnt;
        } else {
          break;
        }
      }
    }
    px = (px + b[x]) % m;
    b[x] = max(b[x] - cnt, 0);
    a[x] = (px - pos(x, 0, b[x], t)) % m;
    if (a[x] < 0) {
      a[x] += m;
    }
    int w = prv[x];
    if (w == x) {
      break;
    }
    cross.erase({ct[w], w});
    cross.erase({ct[x], x});
    ct[w] = time(w);
    ct[x] = time(x);
    cross.insert({ct[w], w});
    cross.insert({ct[x], x});
    gt = t;
  }
  cout << cross.size() << '\n';
  for (auto &f : cross) {
    cout << f.second + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
