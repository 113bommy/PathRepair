#include <bits/stdc++.h>
using namespace std;
long long n, s, pos[6050];
long long prime[10000050], cnt = 0;
bitset<20000000> v;
void get_prime(int n) {
  for (int i = 2; i <= n; i++) {
    if (!v[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
      v[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
void solve() {
  for (int i = 1; i <= n; i++) pos[i] = 1;
  if (!v[s])
    ;
  else if (s % 2 == 0) {
    for (int i = 1; i <= cnt; i++)
      if (!v[s - prime[i]]) {
        pos[prime[i]] = 2;
        break;
      }
  } else if (!v[s - 2])
    pos[2] = 2;
  else {
    pos[3] = 2;
    for (int i = 3; i <= cnt; i++)
      if (!v[s - 3 - prime[i]]) {
        pos[prime[i]] = 3;
        break;
      }
  }
}
int main() {
  scanf("%lld", &n);
  s = n * (n + 1) / 2;
  get_prime(s);
  solve();
  for (int i = 1; i <= n; i++) printf("%lld ", pos[i]);
  return 0;
}
