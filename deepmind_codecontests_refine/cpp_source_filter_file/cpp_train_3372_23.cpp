#include <bits/stdc++.h>
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;
bool v[5000005];
int pref[5000005];
int L;
int divd[1000];
int N, X;
long long expmod(long long a, long long k, long long m) {
  long long b = 1;
  while (k) {
    if (k & 1) b = b * a % m;
    k >>= 1;
    a = a * a % m;
  }
  return b;
}
int main() {
  cin >> N >> X;
  memset(v, 0, sizeof(v));
  v[1] = 1;
  for (int i = (2); i <= (N + 1); i++) {
    if (v[i]) continue;
    pref[i] = i;
    for (int j = (2); j <= (5000005); j++) {
      if (i * j >= 5000005) break;
      v[i * j] = 1;
      pref[i * j] = i;
    }
  }
  if (v[N + 1]) return printf("-1\n"), 0;
  L = 0;
  int x = N;
  while (x > 1) {
    int p = pref[x];
    divd[L++] = p;
    while (x % p == 0) x /= p;
  }
  for (int i = (X - 1); i >= (1); i--) {
    bool fail = 0;
    for (int j = 0; j < (L); j++) {
      long long p = divd[j];
      long long le = expmod(i, p, N + 1);
      if (le == 1) {
        fail = 1;
        break;
      }
      long long re = expmod(i, N / p, N + 1);
      if (re == 1) {
        fail = 1;
        break;
      }
    }
    if (!fail) return printf("%d\n", i), 0;
  }
  printf("-1\n");
  return 0;
}
