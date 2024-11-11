#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> prime;
int c[10000010], s[1000010];
bool flag[10000010];
int phi[10000010], mn[10000010];
void init() {
  phi[1] = 1;
  mn[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!flag[i]) prime.push_back(i), phi[i] = i - 1, mn[i] = i;
    for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
      flag[i * prime[j]] = 1;
      mn[i * prime[j]] = prime[j];
      if (i % prime[j]) {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      } else {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
    }
  }
}
long long ans = 0, s1, s2, s3;
int m;
int main() {
  scanf("%d", &n);
  init();
  m = n - 1;
  for (int i = 2; i <= n; i++) {
    c[mn[i]]++;
    if (!(i > n / 2 && !flag[i]))
      ;
    else
      m--;
  }
  for (int i = 2; i <= n; i++) s[i] = s[i - 1] + c[i];
  for (int i = 2; i <= n; i++) s1 += i - 1 - phi[i];
  for (int i = 2; i <= n; i++) s2 += 1ll * c[i] * s[n / i];
  for (int i = 2; i <= n; i++) {
    if (1ll * mn[i] * mn[i] <= n) s2--;
  }
  s2 /= 2;
  s2 -= s1;
  s3 = 1ll * m * (m - 1) / 2 - s1 - s2;
  printf("%lld\n", s1 + 2 * s2 + 3 * s3);
  return 0;
}
