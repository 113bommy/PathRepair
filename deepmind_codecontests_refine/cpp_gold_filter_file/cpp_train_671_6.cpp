#include <bits/stdc++.h>
using namespace std;
long long n, k, cm[123456], poww10[123456] = {1}, fct[123456] = {1},
                            inv[123456] = {0, 1}, ifct[123456] = {1},
                            ch1[123456], ch2[123456], ans;
char str[123456];
int main() {
  scanf("%lld %lld %s", &n, &k, str);
  for (int i = (0); i < (n); i++) cm[i + 1] = cm[i] + str[i] - '0';
  for (int i = (1); i < (123456); i++)
    poww10[i] = (poww10[i - 1] * 10) % 1000000007LL;
  for (int i = (2); i < (123456); i++)
    inv[i] = ((1000000007LL - 1000000007LL / i) * inv[1000000007LL % i]) %
             1000000007LL;
  for (int i = (1); i < (123456); i++) fct[i] = (fct[i - 1] * i) % 1000000007LL;
  for (int i = (1); i < (123456); i++)
    ifct[i] = (ifct[i - 1] * inv[i]) % 1000000007LL;
  for (int i = (k); i < (n); i++)
    ans = (ans +
           ((((((fct[i - 1] * ifct[k - 1]) % 1000000007LL) * ifct[i - k]) %
              1000000007LL) *
             poww10[n - 1 - i]) %
            1000000007LL) *
               cm[i] +
           ((((((fct[i] * ifct[k]) % 1000000007LL) * ifct[i - k]) %
              1000000007LL) *
             poww10[n - 1 - i]) %
            1000000007LL) *
               (str[i] - '0')) %
          1000000007LL;
  printf("%lld\n", ans);
  return 0;
}
