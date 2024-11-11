#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)2e18;
const string name = "b";
const int NMAX = 11;
const int VMAX = 150000;
const int p = 1000000007;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
long long k;
int n, h, t, ans;
long long delta, step;
map<pair<int, int>, int> d, may, used;
pair<int, int> q[VMAX];
void solve() {
  int res = 0, tmp = d[q[h]];
  pair<int, int> now1, now2;
  while (h < t && d[q[h]] == tmp) {
    int x = q[h].first, y = q[h].second, xx, yy;
    h++;
    for (int i = 0; i < (int)8; i++) {
      xx = x + dx[i], yy = y + dy[i];
      now1 = make_pair(x, y), now2 = make_pair(xx, yy);
      if (!may.count(now2) && !used.count(now2)) {
        res++;
        d[now2] = d[now1] + 1;
        used[now2] = 1;
        q[t++] = now2;
      }
    }
  }
  step = res - delta;
  delta = res;
  if (res == 0) {
    cout << ans << endl;
    exit(0);
  }
  ans = (ans + res) % p;
}
int main() {
  cin >> k >> n;
  k = k % p;
  for (int i = 0; i < (int)n; i++) {
    int x, y;
    cin >> x >> y;
    may[make_pair(x, y)] = 0;
  }
  ans = 1;
  d[make_pair(0, 0)] = 0;
  used[make_pair(0, 0)] = 0;
  h = t = 0;
  q[t++] = make_pair(0, 0);
  delta = step = 0;
  for (int i = 1; i <= min((int)k, 30); ++i) solve();
  long long need = (k - min((int)k, 30)) % p;
  long long sum = (need * (need + 1) / 2) % p;
  cout << (ans + need * delta + sum * step) % p << endl;
  return 0;
}
