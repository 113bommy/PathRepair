#include <bits/stdc++.h>
using namespace std;
int p = 998244353;
vector<vector<long long>> cache(1001, vector<long long>(1001, -1));
long long ncr(int n, int r) {
  if (cache[n][r] == -1)
    cache[n][r] = (ncr(n - 1, r) % p + ncr(n - 1, r - 1) % p) % p;
  return cache[n][r];
}
long long dp(int l, int i, vector<int> &a, int n, vector<int> &table) {
  if (l <= 0) return 0;
  long long ans = 0;
  int j = i + l + 1;
  if (j > n) return 0;
  if (table[i] != -1) return table[i];
  while (j < n) {
    ans = (ans + (ncr(j - i - 1, l) % p * (dp(a[j], j, a, n, table)) % p) % p) %
          p;
    j++;
  }
  ans = (ans + ncr(n - i - 1, l) % p) % p;
  table[i] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cache[i][0] = 1;
    cache[i][i] = 1;
  }
  vector<int> a(n, 0), table(n, -1);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans = (ans % p + dp(a[i], i, a, n, table) % p) % p;
  cout << ans << endl;
  return 0;
}
