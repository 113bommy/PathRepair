#include <bits/stdc++.h>
using namespace ::std;
const long double PI = acos(-1);
const long long MOD = 1000000000 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long add(long long a, long long b, long long m = MOD) {
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = a + b;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long mul(long long a, long long b, long long m = MOD) {
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = a * b;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long pow_mod(long long a, long long b, long long m = MOD) {
  long long res = 1LL;
  a = a % m;
  while (b) {
    if (b & 1) res = mul(res, a, m);
    b >>= 1;
    a = mul(a, a, m);
  }
  return res;
}
long long fastexp(long long a, long long b) {
  long long res = 1LL;
  while (b) {
    if (b & 1) res = res * a;
    b >>= 1;
    a *= a;
  }
  return res;
}
int gcdExtendido(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtendido(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int modInverso(int a, int m) {
  int x, y;
  int g = gcdExtendido(a, m, &x, &y);
  if (g != 1)
    return -1;
  else
    return (x % m + m) % m;
}
const int N = 5000 + 5;
int n, q;
int a[N];
int l[N];
int r[N];
int preffix[3][N];
int query(int L, int R, int x) {
  if (L > R) return 0;
  return preffix[x][R] - preffix[x][L - 1];
}
int main() {
  scanf("%d %d", &(n), &(q));
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &(l[i]), &(r[i]));
    a[l[i]] += 1;
    a[r[i] + 1] -= 1;
  }
  int painted = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    if (a[i] > 0) painted += 1;
  }
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      preffix[i][j] = preffix[i][j - 1];
      if (a[j] == i) preffix[i][j] += 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < q; i++) {
    for (int j = i + 1; j < q; j++) {
      int L1 = l[i];
      int R1 = r[i];
      int L2 = l[j];
      int R2 = r[j];
      if (L1 > L2) {
        swap(L1, L2);
        swap(R1, R2);
      }
      int Li = max(L1, L2);
      int Ri = min(R1, R2);
      int cand = painted;
      if (Li > Ri) {
        cand -= query(L1, R1, 1) + query(L2, R2, 1);
      } else {
        if (Ri < R2)
          cand -=
              query(L1, Li - 1, 1) + query(Li, Ri, 2) + query(Ri + 1, R2, 1);
        else
          cand -=
              query(L1, Li - 1, 1) + query(Li, Ri, 2) + query(Ri + 1, R1, 1);
      }
      ans = max(ans, cand);
    }
  }
  cout << ans << endl;
  return 0;
}
