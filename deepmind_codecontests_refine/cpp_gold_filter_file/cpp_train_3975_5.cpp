#include <bits/stdc++.h>
using namespace std;
long long n, m, kk;
long long mp[109];
pair<long long, pair<long long, long long> > p[100009];
pair<long long, pair<long long, pair<long long, long long> > > p2[100009];
long long inf = 9000000000000000009ll;
long long dp[59][59][59][109];
long long bt(long long id, long long K, long long last, long long more) {
  if (id == m) {
    if (K == n)
      return 0;
    else
      return -inf;
  }
  long long &ret = dp[id][K][last][more];
  if (ret != -1) return ret;
  ret = bt(id + 1, K, last, more);
  if (K == 0) {
    for (long long i = 0; i <= p[id].second.second - p[id].second.first; i++) {
      ret = max(ret, bt(id + 1, 1, id, i) + p[id].second.first + i);
    }
  } else {
    if (p[last].first < p[id].first) {
      long long x = (p[last].second.first + more) * kk;
      long long xx = (p[last].second.first + more) + kk;
      if (x >= p[id].second.first && x <= p[id].second.second)
        ret = max(ret, bt(id + 1, K + 1, id, x - p[id].second.first) + x);
      if (xx >= p[id].second.first && xx <= p[id].second.second)
        ret = max(ret, bt(id + 1, K + 1, id, xx - p[id].second.first) + xx);
    }
  }
  return ret;
}
void path(long long id, long long K, long long last, long long more) {
  if (id == m) return;
  long long ret = bt(id, K, last, more);
  long long ans1 = bt(id + 1, K, last, more);
  if (ans1 == ret) {
    path(id + 1, K, last, more);
    return;
  }
  if (K == 0) {
    for (long long i = 0; i <= p[id].second.second - p[id].second.first; i++) {
      long long ans2 = bt(id + 1, 1, id, i) + p[id].second.first + i;
      if (ans2 == ret) {
        cout << mp[id] << " " << p[id].second.first + i << endl;
        path(id + 1, 1, id, i);
        return;
      }
    }
  } else {
    if (p[last].first < p[id].first) {
      long long x = (p[last].second.first + more) * kk;
      long long xx = (p[last].second.first + more) + kk;
      if (x >= p[id].second.first && x <= p[id].second.second) {
        long long ans3 = bt(id + 1, K + 1, id, x - p[id].second.first) + x;
        if (ans3 == ret) {
          cout << mp[id] << " " << x << endl;
          path(id + 1, K + 1, id, x - p[id].second.first);
          return;
        }
      }
      if (xx >= p[id].second.first && xx <= p[id].second.second) {
        long long ans4 = bt(id + 1, K + 1, id, xx - p[id].second.first) + xx;
        if (ans4 == ret) {
          cout << mp[id] << " " << xx << endl;
          path(id + 1, K + 1, id, xx - p[id].second.first);
          return;
        }
      }
    }
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> kk;
  for (int i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    p[i] = {c, {a, b}};
    p2[i] = {c, {a, {b, i}}};
  }
  sort(p, p + m);
  sort(p2, p2 + m);
  for (int i = 0; i < m; i++) {
    mp[i] = p2[i].second.second.second + 1;
  }
  long long xxx = bt(0, 0, 0, 0);
  if (xxx <= 0)
    cout << "NO" << endl, exit(0);
  else
    cout << "YES" << endl;
  path(0, 0, 0, 0);
}
