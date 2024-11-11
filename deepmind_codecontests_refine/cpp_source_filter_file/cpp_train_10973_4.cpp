#include <bits/stdc++.h>
using namespace std;
int N, M, ar[2200];
long long dn[2200][2200];
const long long mod = 1e9 + 7;
char s[2200];
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) scanf(" %c", &s[i]);
  dn[0][0] = 1;
  for (int sum = 0; sum <= M; sum++) {
    long long k = 0;
    for (int i = 1; i <= N; i++) {
      for (int len = 0; i - len && sum >= (N - i + 1) * (len + 1); len++)
        dn[i][sum] =
            (dn[i][sum] +
             dn[i - len - 1][sum - (N - i + 1) * (len + 1)] * ('z' - s[i])) %
            mod;
      dn[i][sum] = (dn[i][sum] + k * (s[i] - 'a')) % mod;
      k = (k + dn[i][sum]);
    }
  }
  long long res = 0;
  for (int i = 0; i <= N; i++) res = (res + dn[i][M]) % mod;
  cout << res << endl;
  return 0;
}
