#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 1000000 + 10, MAXNUM = 1000000;
int prime[MAXN], isprime[MAXN];
int p[MAXN][7], plen[MAXN];
void get_prime() {
  memset(isprime, 1, sizeof(isprime));
  isprime[1] = false;
  int len = sqrt(MAXNUM + 0.5);
  for (int i = 2; i <= len; i++) {
    if (!isprime[i]) continue;
    for (int j = i * i; j <= MAXNUM; j += i) isprime[j] = false;
  }
}
void get_dqf() {
  int len = sqrt(MAXNUM + 0.5);
  for (int i = 2; i <= MAXNUM; i++) {
    if (prime[i]) continue;
    for (int j = i; j <= MAXNUM; j += i) prime[j] = 1, p[j][plen[j]++] = i;
  }
}
bool ok(int n, int a, int b) {
  for (int i = 0; i < plen[a]; i++) {
    for (int j = 0; j < plen[n]; j++)
      if (p[a][i] == p[n][j]) return false;
  }
  for (int i = 0; i < plen[b]; i++) {
    for (int j = 0; j < plen[n]; j++)
      if (p[b][i] == p[n][j]) return false;
  }
  return true;
}
long long get_max(int n) {
  long long ans = (long long)n * (n - 1);
  for (int i = n - 2; i >= 1; i--) {
    if (ok(i, n, n - 1)) return ans * i;
  }
  return -1;
}
int main() {
  get_dqf();
  get_prime();
  int n;
  while (~scanf("%d", &n)) {
    if (n < 3) {
      printf("%d\n", n);
      continue;
    }
    long long ans = 0;
    for (int i = n; i >= 3; i--) {
      ans = max(ans, get_max(i));
      if (isprime[i]) break;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
