#include <bits/stdc++.h>
using namespace std;
long long comb[1024][1024];
long long calcomb(int n, int k) {
  if (comb[n][k] != -1) return comb[n][k];
  if (n == k || k == 0)
    comb[n][k] = 1;
  else
    comb[n][k] = (calcomb(n - 1, k) + calcomb(n - 1, k - 1)) % 1000000007LL;
  return comb[n][k];
}
long long calc(int n, int m, int k) {
  for (int i = 0; i < (int)1024; i++)
    for (int j = 0; j < (int)1024; j++) comb[i][j] = -1;
  vector<long long> vec1, vec2;
  n--;
  m--;
  for (int i = 0; i < (int)k - 1; i++) {
    vec1.push_back(0);
    vec2.push_back(0);
  }
  for (int i = k - 1; i <= n - 2; i++) vec1.push_back(calcomb(i, k - 1));
  for (int i = k - 1; i <= m - 2; i++) vec2.push_back(calcomb(i, k - 1));
  long long res1 = 0, res2 = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j + i + 2 <= n; j++)
      res1 = (res1 + (vec1[i] * vec1[j]) % 1000000007LL) % 1000000007LL;
  for (int i = 0; i < m; i++)
    for (int j = 0; j + i + 2 <= m; j++)
      res2 = (res2 + (vec2[i] * vec2[j]) % 1000000007LL) % 1000000007LL;
  return (res1 * res2) % 1000000007LL;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (min(n, m) < k + 2) {
    cout << 0 << endl;
    return 0;
  }
  cout << calc(n, m, k) << endl;
}
