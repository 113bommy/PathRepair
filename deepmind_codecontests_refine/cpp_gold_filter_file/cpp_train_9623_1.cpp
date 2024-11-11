#include <bits/stdc++.h>
using namespace std;
long long cum[1000100], p[1000100];
int main() {
  long long n;
  scanf("%I64d", &n);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d", &p[i]);
    ans = ans ^ p[i];
  }
  cum[0] = 0;
  for (long long i = 1; i <= n; i++) cum[i] = cum[i - 1] ^ i;
  for (long long i = 1; i <= n; i++) {
    long long cnt = n / i;
    long long tmp = 0;
    long long num = cum[i - 1];
    long long re = n % i;
    for (long long j = 0; j <= 35; j++) {
      if (num & (1 << j)) {
        if (cnt & 1) tmp = tmp | (1 << j);
      }
    }
    ans = (ans ^ tmp) ^ cum[re];
  }
  cout << ans << endl;
  return 0;
}
