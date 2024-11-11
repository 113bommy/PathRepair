#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int gcd(long long int a, long long int b) {
  if (a < b)
    return gcd(b, a);
  else if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int isPrime(long long int n) {
  long long int p = (long long int)sqrt(n);
  for (int i = (2); i <= (p); i += (1))
    if (n % i == 0) return 0;
  return 1;
}
long long int pow(long long int b, long long int e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long int a = pow(b, e / 2);
    return a * a;
  } else {
    long long int a = pow(b, e / 2);
    return b * a * a;
  }
}
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modInverse(long long int a, long long int m) {
  return powm(a, m - 2, m);
}
int n;
vector<int> arr(105);
vector<vector<vector<vector<int>>>> dp(
    105,
    vector<vector<vector<int>>>(105,
                                vector<vector<int>>(105, vector<int>(2, -1))));
int rec(int i, int e, int o, int last) {
  if (e < 0 or o < 0) return INT_MAX;
  if (i == n) return 0;
  if (dp[i][e][o][last] != -1) return dp[i][e][o][last];
  if (arr[i] != 0)
    return dp[i][e][o][last] =
               ((arr[i] & 1) != last) + rec(i + 1, e, o, arr[i] & 1);
  int ee = rec(i + 1, e - 1, o, 0);
  int oo = rec(i + 1, e, o - 1, 1);
  if (ee != INT_MAX) ee += (last != 0);
  if (oo != INT_MAX) oo += (last != 1);
  return dp[i][e][o][last] = min(ee, oo);
}
void solve() {
  cin >> n;
  int p[2] = {};
  for (int i = (0); i <= (n - 1); i += (1)) {
    cin >> arr[i];
    if (arr[i] != 0) p[arr[i] & 1]++;
  }
  int e = n / 2 - p[0], o = n / 2 + (n & 1) - p[1];
  int ans = INT_MAX;
  if (arr[0] != 0)
    ans = rec(1, e, o, arr[0] & 1);
  else {
    int ee = rec(1, e - 1, o, 0);
    int oo = rec(1, e, o - 1, 1);
    ans = min({ans, ee, oo});
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
