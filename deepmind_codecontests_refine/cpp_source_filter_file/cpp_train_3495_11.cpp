#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7, P = 1e9 + 7;
int Px[MAX], f[MAX], iv[MAX];
vector<int> pr;
int fpow(int b, int p) {
  long long int r = 1;
  while (p) {
    if (p & 1) r *= b, r %= P;
    b = 1ll * b * b % P;
    p >>= 1;
  }
  return r;
}
void pre() {
  for (int i = 2; i < MAX; ++i) {
    if (!Px[i]) {
      Px[i] = i;
      pr.emplace_back(i);
    }
    for (int p : pr) {
      if (1ll * p * i >= MAX) break;
      Px[p * i] = p;
      if (i % p == 0) break;
    }
  }
  f[0] = 1, iv[0] = 1;
  for (int i = 1; i < MAX; ++i) {
    f[i] = 1ll * f[i - 1] * i % P;
    iv[i] = fpow(f[i], P - 2);
  }
}
int C(int n, int k) {
  int r = 1ll * f[n] * iv[k] % P;
  return 1ll * r * iv[n - k] % P;
}
int calc(int e, int r) {
  int res = 0;
  for (int i = 0; i <= e; ++i) {
    res += (i ? 2ll * C(e + r - 1 - i, r - 1) % P : C(e + r - 1 - i, r - 1));
    if (res >= P) res -= P;
  }
  return res;
}
int fun(int n, int r) {
  int ans = 1;
  while (Px[n]) {
    int cp = Px[n], e = 0;
    while (n % cp == 0) {
      n /= cp;
      ++e;
    }
    if (r == 0)
      ans = 2ll * ans % P;
    else
      ans = 1ll * ans * calc(e, r) % P;
  }
  return ans;
}
int main() {
  pre();
  int q;
  scanf("%d", &q);
  while (q--) {
    int r, n;
    scanf("%d%d", &r, &n);
    printf("%d\n", fun(n, r));
  }
  return 0;
}
