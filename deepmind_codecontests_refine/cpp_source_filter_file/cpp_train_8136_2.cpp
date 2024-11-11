#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int N = 200005;
long long int a[N], b[N], dp[N][2], n;
long long int hello(long long int i, long long int last) {
  if (i == n) return 0;
  long long int& ans = dp[i][last];
  if (ans != -1) return ans;
  if (last == 0) {
    ans = max(ans, a[i] + hello(i + 1, 1));
    ans = max(ans, b[i] + hello(i + 1, 2));
  } else if (last == 1)
    ans = max(ans, b[i] + hello(i + 1, 2));
  else if (last == 2)
    ans = max(ans, a[i] + hello(i + 1, 1));
  ans = max(ans, hello(i + 1, 0));
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) cin >> b[i];
  cout << hello(0, 0);
  return 0;
}
