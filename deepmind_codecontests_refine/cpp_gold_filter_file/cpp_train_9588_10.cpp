#include <bits/stdc++.h>
const int maxn = 70;
using namespace std;
vector<int> prime;
int mu[maxn];
bool vis[maxn];
void make_table() {
  mu[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      mu[i] = -1;
      prime.push_back(i);
    }
    for (int j = 0; j < (int)prime.size() && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else
        mu[i * prime[j]] = -mu[i];
    }
  }
}
long long n;
long long solve() {
  long long ans = 0;
  for (int i = 1; i <= 60; i++) {
    if (!mu[i]) continue;
    ans += 1ll * mu[i] *
           ((long long)powl((long double)n + 0.1, (long double)1.0 / i) - 1);
  }
  return ans;
}
int main() {
  make_table();
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d", &n);
    printf("%I64d\n", solve());
  }
  return 0;
}
