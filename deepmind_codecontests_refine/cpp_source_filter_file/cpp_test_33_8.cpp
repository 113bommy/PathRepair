#include <bits/stdc++.h>
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = bigmod(a, b / 2);
  return ret * ret % 1000000007 * (b % 2 ? a : 1) % 1000000007;
}
using namespace std;
int n;
int v[200010];
int dp[520], cp[520];
vector<int> A;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= 512; i++) cp[i] = 1e9;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int h = 512; h >= 0; h--) {
      if (dp[h] == 1 && cp[h] < v[i] && cp[h ^ v[i]] > v[i]) {
        dp[h ^ v[i]] = 1;
        cp[h ^ v[i]] = v[i];
      }
    }
  }
  for (int i = 0; i <= 500; i++)
    if (dp[i]) A.push_back(i);
  cout << A.size() << "\n";
  for (auto i : A) cout << i << " ";
}
