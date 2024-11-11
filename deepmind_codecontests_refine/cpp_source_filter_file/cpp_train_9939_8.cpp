#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, HA = 19260817;
int n;
map<int, long long> aka;
set<int> vals;
long long aa[N], xx[N], cc[N], oo[N], hh[N], ww[N];
long long ran() {
  static long long se = 1;
  return se *= 1000003;
}
int eq(int s, int t, int l) {
  return (oo[s] - oo[s + l] * hh[l]) * hh[n + 1 - t] ==
         (cc[t] - cc[t - l] * hh[l]) * hh[s];
}
int wq(int s, int t, int l) {
  return (ww[s + l - 1] - ww[s - 1]) == (ww[t] - ww[t - l]);
}
long long solve() {
  int o = 0, i = 0;
  long long re = 0;
  while (o < n && eq(1, n, o + 1)) ++o;
  if (o == n) cout << 1LL * n * (n + 1) / 2, exit(0);
  while (i * 2 < n && eq((n + 1) / 2 - i, n / 2 + 1 + i, i + 1)) ++i;
  if (wq(1 + o, n - o, (n + 1) / 2 - i - o)) re += 2LL * (1 + o) * max(i, 1);
  cerr << "i= " << i << "    "
       << "o= " << o << endl;
  cerr << "re= " << re << endl;
  if (vals.find(xx[n - o] ^ xx[o]) != vals.end() ||
      vals.find(xx[o] ^ xx[n - o]) != vals.end()) {
    re += 1LL * o * o - 1;
    {
      map<long long, int> cn;
      for (int i = o + 1; i <= n - o; ++i) ++cn[aa[i]];
      int r = n - o;
      while (cn[aa[r]] - 2 >= 0) cn[aa[r--]] -= 2;
      re += (n - o - r + 1) * (1LL + o);
      cerr << "r= " << r << endl;
    }
    {
      map<long long, int> cn;
      for (int i = o + 1; i <= n - o; ++i) ++cn[aa[i]];
      int l = o + 1;
      while (cn[aa[l]] - 2 >= 0) cn[aa[l++]] -= 2;
      re += (l - o) * (1LL + o);
      cerr << "l= " << l << endl;
    }
  }
  return re;
}
int main() {
  ios::sync_with_stdio(0);
  vals.insert(0);
  hh[0] = 1;
  for (int i = 1; i <= N - 1; ++i) hh[i] = hh[i - 1] * HA;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (!aka.count(x)) vals.insert(aka[x] = ran());
    aa[i] = aka[x];
  }
  for (int i = 1; i <= n; ++i) xx[i] = xx[i - 1] ^ aa[i];
  for (int i = 1; i <= n; ++i) cc[i] = cc[i - 1] * HA + aa[i];
  for (int i = n; i >= 1; --i) oo[i] = oo[i + 1] * HA + aa[i];
  for (int i = 1; i <= n; ++i) ww[i] = ww[i - 1] + aa[i];
  cout << solve();
}
