#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
const long long M = 1000000007;
long long C[5 * N], D[5 * N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string A, B;
  cin >> A >> B;
  long long n = B.length();
  long long k = A.length();
  C[0] = B[0] - '0';
  for (long long i = 1; i < n; i++) {
    C[i] = (2 * C[i - 1] + B[i] - '0') % M;
  }
  long long cnt = 1;
  D[n - 1] = B[n - 1] - '0';
  for (long long i = n - 2; i >= 0; i--) {
    cnt = (cnt * 2) % M;
    D[i] = (cnt * (B[i] - '0') + D[i + 1]) % M;
  }
  long long flag = n;
  for (long long i = 1; i < n; i++) {
    if (D[i] == C[n - 1 - i]) {
      flag = i;
      break;
    }
  }
  string E;
  for (long long i = n - flag; i < n; i++) E += B[i];
  for (long long i = 0; i < n; i++) {
  }
  long long a = 0, b = 0, c = 0, d = 0;
  long long p = 0, q = 0;
  long long m = E.length();
  for (long long i = 0; i < n; i++) {
    if (B[i] == '1')
      a++;
    else
      b++;
  }
  for (long long i = 0; i < m; i++) {
    if (E[i] == '1')
      c++;
    else
      d++;
  }
  for (long long i = 0; i < k; i++) {
    if (A[i] == '1')
      p++;
    else
      q++;
  }
  string ans;
  if (p >= a && q >= b) ans = B, p -= a, q -= b;
  while (p >= c && q >= d) {
    ans += E;
    p -= c, q -= d;
  }
  for (long long i = 0; i < p; i++) ans += '1';
  for (long long i = 0; i < q; i++) ans += '0';
  cout << ans;
  return 0;
}
