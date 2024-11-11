#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << " " << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void inp_out() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  inp_out();
  long long int n;
  cin >> n;
  long long int total = 0;
  vector<long long int> a(n);
  for (long long int i = 0; i < (n + 1) / 2; ++i) {
    cin >> a[i];
    total += a[i];
  }
  long long int x;
  cin >> x;
  for (long long int i = (n + 1) / 2; i < n; ++i) a[i] = x;
  total += (x * (n / 2));
  if (x >= 0) {
    if (total > 0)
      cout << n;
    else
      cout << -1;
    return 0;
  } else {
    vector<long long int> pre(n + 1);
    for (long long int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i - 1];
    vector<long long int> pre2(n + 1);
    for (long long int i = 1; i <= n; ++i)
      pre2[i] = max(pre[i] - i * x, pre2[i - 1]);
    long long int ans = -1;
    for (long long int i = (n + 1) / 2; i <= n; ++i) {
      if (pre[i] > pre2[n - i]) ans = i;
    }
    cout << ans;
  }
  return 0;
}
