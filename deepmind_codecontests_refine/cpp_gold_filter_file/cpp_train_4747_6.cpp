#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int k;
  cin >> k;
  long long int res = -1;
  if (k > (long long int)1e6) {
    cout << -1 << endl;
    return 0;
  } else if (n < (k * (k + 1)) / 2) {
    cout << -1 << endl;
    return 0;
  }
  for (long long int i = 1; i * i <= n; i++) {
    long long int j = i;
    long long int sum = j * (k * (k - 1)) / 2;
    long long int j2 = n / i;
    long long int sum2 = j2 * (k * (k - 1)) / 2;
    if (n - sum > (k - 1) * j and (n - sum) % i == 0) res = max(res, i);
    if (n - sum2 > (k - 1) * j2 and (n - sum2) % j2 == 0) res = max(res, j2);
  }
  if (res == -1)
    cout << -1 << endl;
  else {
    k--;
    long long int ans = res;
    long long int sum = 0;
    while (k--) {
      cout << ans << " ";
      sum += ans;
      ans = ans + res;
    }
    cout << n - sum << endl;
  }
  return 0;
}
