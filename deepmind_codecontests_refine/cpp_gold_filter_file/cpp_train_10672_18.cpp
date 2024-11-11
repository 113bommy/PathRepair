#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int N = 1e5 + 5;
double pos[N];
double getExpe(int l, int r, int p) {
  int ans = ((r / p) - ((l - 1) / p));
  return double(ans) / (r - l + 1);
}
double calculate(int x, int n, int p) {
  int l = (x == 1 ? n : x - 1);
  int r = (x == n ? 1 : x + 1);
  return pos[x] * (2.0 - pos[l] / 2 - pos[r] / 2);
}
int main() {
  int l, r, n, p;
  double ans = 0.0;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    pos[i] = getExpe(l, r, p);
  }
  for (int i = 1; i <= n; i++) {
    ans += calculate(i, n, p);
  }
  printf("%.9f\n", ans * 1000.0 * 2);
  return 0;
}
