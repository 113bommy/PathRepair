#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, c;
int a[maxn];
long long sum[maxn], dp[maxn];
multiset<int> S;
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = sum[i] = a[i] + sum[i - 1];
  }
  for (int i = 1; i < c; i++) S.insert(a[i]);
  for (int i = c; i <= n; i++) {
    S.insert(a[i]);
    dp[i] = min(dp[i - 1] + a[i], dp[i - c] + sum[i] - sum[i - c] - *S.begin());
    S.erase(a[i - c + 1]);
  }
  cout << dp[n] << endl;
  return 0;
}
