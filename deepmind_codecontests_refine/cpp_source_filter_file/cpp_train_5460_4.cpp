#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
const int sqrt5 = 383008016;
const int Invsqrt5 = 276601605;
const int Inv5 = (mod + 1) / 5;
const int AA = 691504013;
const int BB = 308495997;
int n;
int a[300005], pwA[300005], pwB[300005];
int sumA[300005], sumB[300005];
int sum[1200005], sum1[1200005], sum2[1200005];
int tag1[1200005], tag2[1200005];
inline void setIO(string a) {}
void UP(int &x, int y) {
  x += y;
  while (x >= mod) x -= mod;
}
int l, r, ans;
void build(int x, int L, int R) {
  int md = (L + R) >> 1;
  if (L == R) {
    sum[x] = a[L];
    return;
  }
  build(x * 2, L, md);
  build(x * 2 + 1, md + 1, R);
  sum[x] = sum[x * 2];
  UP(sum[x], sum[x * 2 + 1]);
}
inline void Tag(int x, int A, int B, int l, int r) {
  UP(tag1[x], A);
  UP(tag2[x], B);
  UP(sum1[x], 1ll * A * sumA[r - l] % mod);
  UP(sum2[x], 1ll * B * sumB[r - l] % mod);
}
inline void down(int x, int l, int r) {
  if (tag1[x] == 0 && tag2[x] == 0) return;
  int md = (l + r) >> 1;
  Tag(x * 2, tag1[x], tag2[x], l, md);
  Tag(x * 2 + 1, 1ll * tag1[x] * pwA[md - l + 1] % mod,
      1ll * tag2[x] * pwB[md - l + 1] % mod, md + 1, r);
  tag1[x] = tag2[x] = 0;
}
int p = 0;
void Modify(int x, int L, int R) {
  if (l <= L && R <= r) {
    UP(tag1[x], pwA[p + 1]);
    UP(tag2[x], pwB[p + 1]);
    UP(sum1[x], sumA[p + R - L + 1]);
    UP(sum1[x], mod - sumA[p]);
    UP(sum2[x], sumB[p + R - L + 1]);
    UP(sum2[x], mod - sumA[p]);
    p += R - L + 1;
    return;
  }
  down(x, L, R);
  int md = (L + R) >> 1;
  if (l <= md) Modify(x * 2, L, md);
  if (md < r) Modify(x * 2 + 1, md + 1, R);
  sum1[x] = sum1[x * 2];
  UP(sum1[x], sum1[x * 2 + 1]);
  sum2[x] = sum2[x * 2];
  UP(sum2[x], sum2[x * 2 + 1]);
}
void ask(int x, int L, int R) {
  if (l <= L && R <= r) {
    int t = sum1[x];
    UP(t, mod - sum2[x]);
    t = 1ll * t * Invsqrt5 % mod;
    UP(ans, sum[x]);
    UP(ans, t);
    return;
  }
  down(x, L, R);
  int md = (L + R) >> 1;
  if (l <= md) ask(x * 2, L, md);
  if (md < r) ask(x * 2 + 1, md + 1, R);
}
int m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  build(1, 1, n);
  sumA[0] = pwA[0] = 1;
  for (int i = (1); i <= (n); i++) pwA[i] = 1ll * pwA[i - 1] * AA % mod;
  sumB[0] = pwB[0] = 1;
  for (int i = (1); i <= (n); i++) pwB[i] = 1ll * pwB[i - 1] * BB % mod;
  for (int i = (1); i <= (n); i++) sumA[i] = sumA[i - 1], UP(sumA[i], pwA[i]);
  for (int i = (1); i <= (n); i++) sumB[i] = sumB[i - 1], UP(sumB[i], pwB[i]);
  for (int i = (1); i <= (m); i++) {
    int type;
    scanf("%d%d%d", &type, &l, &r);
    if (type == 1) {
      p = 0;
      Modify(1, 1, n);
    } else {
      ans = 0;
      ask(1, 1, n);
      printf("%d\n", ans);
    }
  }
  return 0;
}
