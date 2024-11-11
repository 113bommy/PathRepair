#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
} p[1005];
long long n, r[1005], components, who[1005], num[1005];
vector<long long> pox, poy, vec[4];
bool sx(long long a, long long b) {
  if (p[a].x == p[b].x) return p[a].y < p[b].y;
  return p[a].x < p[b].x;
}
bool sy(long long a, long long b) {
  if (p[a].y == p[b].y) return p[a].x < p[b].x;
  return p[a].y < p[b].y;
}
long long Find(long long a) {
  if (r[a] == a) return a;
  return r[a] = Find(r[a]);
}
void merge(long long a, long long b) {
  long long ra = Find(a), rb = Find(b);
  if (ra != rb) {
    components--;
    r[ra] = rb;
  }
}
bool check(long long T) {
  components = n;
  for (long long i = 1; i <= n; i++) r[i] = i;
  for (long long i = 1; i < n; i++) {
    long long a = pox[i - 1], b = pox[i];
    if (p[a].x == p[b].x && abs(p[a].y - p[b].y) <= T) merge(a, b);
    a = poy[i - 1], b = poy[i];
    if (p[a].y == p[b].y && abs(p[a].x - p[b].x) <= T) merge(a, b);
  }
  if (components > 4) return 0;
  if (components <= 1) return 1;
  for (long long i = 0; i < 4; i++) who[i] = 0, vec[i].clear();
  for (long long i = 1; i <= n; i++) {
    r[i] = Find(i);
    for (long long j = 0; j < 4; j++) {
      if (!who[j]) who[j] = r[i];
      if (who[j] == r[i]) {
        vec[j].push_back(i);
        num[i] = j;
        break;
      }
    }
  }
  if (components == 2) {
    for (auto i : vec[0])
      for (auto j : vec[1]) {
        if (p[i].x == p[j].x && abs(p[i].y - p[j].y) <= 2 * T) return 1;
        if (p[i].y == p[j].y && abs(p[i].x - p[j].x) <= 2 * T) return 1;
        if (abs(p[i].x - p[j].x) <= T && abs(p[i].y - p[j].y) <= T) return 1;
      }
    return 0;
  }
  if (components == 3) {
    for (long long i = 1; i < n; i++) {
      long long a = pox[i - 1], b = pox[i];
      if (r[a] != r[b] && p[a].x == p[b].x && abs(p[a].y - p[b].y) <= 2 * T) {
        for (auto c : vec[3 - num[a] - num[b]]) {
          if (abs(p[c].x - p[a].x) <= T && abs(p[a].y - p[c].y) <= T &&
              abs(p[b].y - p[c].y) <= T)
            return 1;
        }
      }
    }
    for (long long i = 1; i < n; i++) {
      long long a = poy[i - 1], b = poy[i];
      if (r[a] != r[b] && p[a].y == p[b].y && abs(p[a].x - p[b].x) <= 2 * T) {
        for (auto c : vec[3 - num[a] - num[b]]) {
          if (abs(p[c].y - p[a].y) <= T && abs(p[a].x - p[c].x) <= T &&
              abs(p[b].x - p[c].x) <= T)
            return 1;
        }
      }
    }
    return 0;
  }
  for (long long i = 1; i < n; i++) {
    long long a = pox[i - 1], b = pox[i];
    if (r[a] != r[b] && p[a].x == p[b].x && abs(p[a].y - p[b].y) <= 2 * T) {
      for (long long j = 1; j < n; j++) {
        long long c = poy[i - 1], d = poy[i];
        if (r[c] != r[a] && r[c] != r[b] && r[c] != r[d] && r[d] != r[a] &&
            r[d] != r[b]) {
          if (p[c].y == p[d].y && abs(p[c].x - p[d].x) <= 2 * T) {
            long long X = p[a].x, Y = p[c].y;
            if (p[a].y <= Y && Y <= p[b].y && p[c].x <= X && X <= p[d].x) {
              if (abs(p[a].y - Y) <= T && abs(p[b].y - Y) <= T &&
                  abs(p[c].x - X) <= T && abs(p[d].x - X) <= T)
                return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
int32_t main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
    pox.push_back(i);
    poy.push_back(i);
  }
  sort(pox.begin(), pox.end(), sx);
  sort(poy.begin(), poy.end(), sy);
  long long l = 1, r = 3e9;
  long long mid = (l + r) >> 1;
  while (l != r) {
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
    mid = (l + r) >> 1;
  }
  cout << (mid == 3e9 ? -1 : mid);
}
