#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
const int maxn = 1e5 + 5;
const long long mo = 998244353;
long long n;
long long w[maxn];
long long C[55];
long long cnt[maxn];
long long table[5000];
int main() {
  scanf("%lld", &n);
  memset(cnt, 0, sizeof(cnt));
  memset(C, 0, sizeof(C));
  table[1] = 1;
  for (int i = 2; i <= 150; i++) table[i] = table[i - 1] * 10 % mo;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
    long long t = w[i];
    while (t) {
      cnt[i]++;
      t /= 10;
    }
    C[cnt[i]]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long t = w[i];
    long long a = 0, b = 0, c = 0;
    long long tmp = 1;
    while (t) {
      long long a = t % 10;
      t /= 10;
      for (int j = 1; j <= 11; j++) {
        if (j >= tmp) {
          ans += a * table[2 * tmp - 1] % mo * C[j] % mo;
          ans %= mo;
          ans += a * table[2 * tmp] % mo * C[j] % mo;
          ans %= mo;
        } else {
          ans += a * table[2 * j + tmp - j] % mo * C[j] % mo;
          ans %= mo;
          ans += a * table[2 * j + tmp - j] % mo * C[j] % mo;
          ans %= mo;
        }
      }
      tmp++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
