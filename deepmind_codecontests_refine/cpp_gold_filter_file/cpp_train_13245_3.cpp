#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long hell = round(1e18);
signed solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long mx = 0;
  vector<long long> v1(n);
  vector<long long> a(n + 1);
  vector<long long> b(n + 1);
  for (long long i = 0; i < n; i++) {
    v1[v[i]]++;
    if (v1[v[i]] > 1) break;
    mx = max(mx, v[i]);
    if (mx == i + 1) a[i + 1] = 1;
  }
  reverse((v).begin(), (v).end());
  vector<long long> v2(n);
  mx = 0;
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    v2[v[i]]++;
    if (v2[v[i]] > 1) break;
    mx = max(mx, v[i]);
    if (mx == i + 1) {
      b[i + 1] = 1;
      if (a[n - i - 1] == 1) c++;
    }
  }
  cout << c << endl;
  for (long long i = 1; i < n; i++) {
    if (a[i] == 1 & b[n - i] == 1) {
      cout << i << " " << n - i << endl;
    }
  }
  return 0;
}
signed main() {
  long long t = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
