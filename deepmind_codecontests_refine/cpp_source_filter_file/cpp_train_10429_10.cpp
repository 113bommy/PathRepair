#include <bits/stdc++.h>
using namespace std;
bool is_prime[1000001];
int phi[1000001], prime[1000001], tot;
void get_phi(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] == false) {
      prime[tot++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < tot && i * prime[j] <= n; j++) {
      is_prime[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      }
    }
  }
}
int main() {
  int n, k, i;
  scanf("%d%d", &n, &k);
  get_phi(n);
  long long ans = 2;
  sort(phi + 3, phi + n + 1);
  for (i = 1; i <= k; i++) {
    ans = ans + phi[i + 2];
  }
  if (k == 1) ans = 3;
  printf("%d\n", ans);
  return 0;
}
