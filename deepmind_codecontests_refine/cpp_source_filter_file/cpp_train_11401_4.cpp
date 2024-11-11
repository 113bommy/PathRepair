#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxlog = 20;
const long long inf = 1e18;
const int mod = 1e9 + 7;
const long long base = 307;
int a[maxn];
int dp[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) ans++;
  }
  cout << max(ans + 2, n);
  return 0;
}
