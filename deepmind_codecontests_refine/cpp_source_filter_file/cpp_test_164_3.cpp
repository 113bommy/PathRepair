#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, k;
  string s;
  cin >> n >> k >> s;
  vector<long long> l(n), r(n), val(n), d(n, 0), in;
  for (long long i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    --l[i], --r[i];
  }
  function<void(long long)> dfs = [&](long long v) {
    if (v == -1) return;
    dfs(l[v]);
    in.push_back(v);
    dfs(r[v]);
  };
  dfs(0);
  val[in.back()] = 0;
  for (long long i = n - 2; i >= 0; i--) {
    if (s[in[i]] == s[in[i + 1]])
      val[in[i]] = val[in[i + 1]];
    else if (s[in[i]] < s[in[i + 1]])
      val[in[i]] = 1;
    else
      val[in[i]] = -1;
  }
  function<long long(long long, long long)> dfs2 = [&](long long v,
                                                       long long t) {
    if (v == -1 or t == 0) return 0ll;
    long long x = dfs2(l[v], t - 1);
    if (val[v] == 1 or x) x++;
    if (x) d[v] = 1;
    long long rem = t - x;
    if (!d[v]) rem = 0;
    dfs2(r[v], rem);
    return x;
  };
  dfs2(0, k);
  for (auto i : in) {
    cout << s[i];
    if (d[i]) cout << s[i];
  }
}
