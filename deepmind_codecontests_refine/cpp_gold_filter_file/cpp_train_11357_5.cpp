#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const long long base2 = 233;
const long long base1 = 231;
const long long mod = 1e9 + 7;
const long long hmod1 = 1e9 + 93;
const long long hmod2 = 1e9 + 97;
const double e = exp(1.0);
const double pi = acos(-1);
long long sum1[305] = {0}, sum2[305] = {};
int len[305] = {0};
long long quick_pow(long long a, int n, long long hmod) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % hmod;
    n /= 2;
    a = (a * a) % hmod;
  }
  return ans;
}
int main() {
  int n;
  string s;
  while (scanf("%d", &n) != EOF) {
    long long ans = 0, sum;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      long long a1 = 0, a2 = 0;
      int l = s.length();
      ans += l;
      len[i] = len[i - 1] + l;
      for (int j = 0; j < l; j++) {
        a1 = (a1 * base1 + (long long)s[j]) % hmod1;
        a2 = (a1 * base2 + (long long)s[j]) % hmod2;
      }
      sum1[i] = (sum1[i - 1] * base1 + a1) % hmod1;
      sum2[i] = (sum2[i - 1] * base2 + a2) % hmod2;
    }
    ans += n - 1;
    sum = ans;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int num = 0, l = j - i + 1;
        for (int k = j + 1; k + l - 1 <= n; k++) {
          long long bit1 = quick_pow(base1, l, hmod1);
          long long bit2 = quick_pow(base2, l, hmod2);
          if ((((sum2[j] - (bit2 * sum2[i - 1]) % hmod2) % hmod2) + hmod2) %
                  hmod2 ==
              ((sum2[k + l - 1] - (bit2 * sum2[k - 1]) % hmod2) % hmod2 +
               hmod2) %
                  hmod2)
            k += l, k--, num++;
        }
        if (num) ans = min(ans, sum - ((num + 1) * (len[j] - len[i - 1] - 1)));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
