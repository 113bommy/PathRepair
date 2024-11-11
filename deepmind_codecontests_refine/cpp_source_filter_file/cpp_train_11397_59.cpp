#include <bits/stdc++.h>
using namespace std;
long long f[100], f0[100];
int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i < k; i++) f0[i] = 0, f[i] = 0;
  int tmp = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    f0[0] = 1;
    for (int j = 0; j < k; j++)
      if (f0[j] > 0) {
        for (int p = 0; p < 10; p++) {
          f[(p * tmp + j) % k] = (f[(p * tmp + j) % k] + f0[j]) % m;
        }
      }
    tmp = tmp * 10 % k;
    long long asd = 1;
    for (int j = i + 1; j < n - 1; j++) asd = asd * 10 % m;
    if (i + 1 < n) asd = (asd * 9) % m;
    ans = (ans + asd * (f[0] - 1)) % m;
    f[0] = 0;
    memcpy(f0, f, sizeof f0);
    memset(f, 0, sizeof f);
  }
  cout << ans << endl;
  return 0;
}
