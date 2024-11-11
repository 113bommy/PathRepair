#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9) + 7;
long long d[2020][2020], sum[2020], ans;
int n, K, Next;
string s;
int main() {
  cin >> n >> K >> s;
  d[0][0] = 1;
  sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= K; k++) {
      (d[i][k] += sum[k] * ((i == n) + s[i - 1] - 'a')) %= mod;
      for (int j = i; j >= 1; j--) {
        Next = (i - j + 1) * (n - i + 1);
        if (k < Next) break;
        (d[i][k] += d[j - 1][k - Next] * (26 - (s[i - 1] - 'a' + 1))) % mod;
      }
    }
    for (int k = 0; k <= K; k++) (sum[k] += d[i][k]) %= mod;
  }
  cout << d[n][K];
  return 0;
}
