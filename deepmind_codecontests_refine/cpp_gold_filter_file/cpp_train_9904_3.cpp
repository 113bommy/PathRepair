#include <bits/stdc++.h>
using namespace std;
void stress();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stress();
}
const long long MAXN = 1e5 + 5;
pair<long long, long long> t[4 * MAXN];
long long a[MAXN];
long long p[4 * MAXN];
pair<long long, long long> comb(pair<long long, long long> a,
                                pair<long long, long long> b) {
  return {min(a.first, b.first), max(a.second, b.second)};
}
void build(long long v, long long tl, long long tr) {
  if (tl == tr)
    t[v] = {a[tl], a[tl]};
  else {
    long long mid = tl + tr >> 1;
    build(v << 1, tl, mid);
    build(v << 1 | 1, mid + 1, tr);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
}
void push(long long v) {
  if (p[v]) {
    t[v << 1].first += p[v];
    t[v << 1].second += p[v];
    t[v << 1 | 1].first += p[v];
    t[v << 1 | 1].second += p[v];
    p[v << 1] += p[v];
    p[v << 1 | 1] += p[v];
    p[v] = 0;
  }
}
void update(long long v, long long tl, long long tr, long long l, long long r,
            long long x) {
  if (tl == l && tr == r) {
    t[v].first += x;
    t[v].second += x;
    p[v] += x;
  } else {
    push(v);
    long long mid = tl + tr >> 1;
    if (l <= mid) update(v << 1, tl, mid, l, min(r, mid), x);
    if (r > mid) update(v << 1 | 1, mid + 1, tr, max(l, mid + 1), r, x);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
}
long long getmax() { return t[1].second; }
long long getmin() { return t[1].first; }
vector<pair<long long, long long>> que;
bool cmp(pair<pair<long long, long long>, long long> a,
         pair<pair<long long, long long>, long long> b) {
  if (a.first.first != b.first.first) return a.first.first < b.first.first;
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return que[a.second].second < que[b.second].second;
}
void stress() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> a[i];
  build(1, 0, n - 1);
  vector<pair<pair<long long, long long>, long long>> q;
  for (long long j = 0; j < m; j++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    que.push_back({x, y});
    q.push_back({{x, 0}, j});
    q.push_back({{y, 1}, j});
  }
  set<long long> ans;
  sort(q.begin(), q.end(), cmp);
  long long l = 0;
  long long mx = getmax() - getmin();
  set<long long> cur;
  for (long long i = 0; i < n; i++) {
    while (l < q.size() && q[l].first.first == i && q[l].first.second == 0) {
      long long j = q[l].second;
      update(1, 0, n - 1, que[j].first, que[j].second, -1);
      cur.insert(j);
      long long cursum = getmax() - getmin();
      if (cursum > mx) {
        mx = cursum;
        ans = cur;
      }
      l++;
    }
    long long cursum = getmax() - getmin();
    if (cursum > mx) {
      mx = cursum;
      ans = cur;
    }
    while (l < q.size() && q[l].first.first == i && q[l].first.second == 1) {
      long long j = q[l].second;
      update(1, 0, n - 1, que[j].first, que[j].second, 1);
      cur.erase(j);
      l++;
    }
  }
  cout << mx << endl << ans.size() << endl;
  for (auto it : ans) cout << it + 1 << " ";
}
