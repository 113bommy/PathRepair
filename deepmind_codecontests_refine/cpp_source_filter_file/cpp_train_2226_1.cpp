#include <bits/stdc++.h>
using namespace std;
long long po(long long b, long long e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  long long med = po(b, e / 2);
  med = (med * med) % 1000000007;
  if (e % 2) return (med * b) % 1000000007;
  return med;
}
long long p[1005][1005];
void pasc() {
  p[0][0] = 1;
  for (int i = 1; i < 1005; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= i; j++)
      p[i][j] = (p[i - 1][j] + p[i - 1][j - 1]) % 1000000007;
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = 1;
  ans = (ans * po(3, n - k)) % 1000000007;
  ans = (ans * po(k, k - 1)) % 1000000007;
  cout << ans << endl;
}
