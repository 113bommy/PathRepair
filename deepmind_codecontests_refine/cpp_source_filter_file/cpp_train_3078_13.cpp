#include <bits/stdc++.h>
using namespace std;
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T POW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return SQR(POW(B, printf / 2));
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T bpow(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int ts, kk = 1;
int n, l1, l2;
pair<pair<int, int>, int> a[3005];
int p[3005][3005];
bool nx[3005][3005];
int dp(int i, int r) {
  if (i == n) {
    if (r == 0) return 0;
    return -(1 << 30);
  }
  int &pr = p[i][r];
  if (pr != -1) return pr;
  pr = 0;
  int q;
  if (r) {
    q = dp(i + 1, r - 1) + a[i].first.second;
    if (q > pr) {
      pr = q;
      nx[i][r] = 1;
    }
  }
  if (n - i - 1 >= r) {
    q = dp(i + 1, r) + (((n - r - l1) <= i) ? a[i].first.first : 0);
    if (q > pr) {
      pr = q;
      nx[i][r] = 0;
    }
  }
  return pr;
}
int ls[2][3005], ln[2];
void prnt(int i, int r) {
  if (i == n) return;
  if (nx[i][r]) {
    ls[0][ln[0]++] = a[i].second;
    prnt(i + 1, r - 1);
    return;
  }
  if ((n - r - l1) <= i) {
    ls[1][ln[1]++] = a[i].second;
  }
  prnt(i + 1, r);
}
int main() {
  int t, i, j, k;
  memset(p, -1, sizeof(p));
  scanf("%d%d%d", &n, &l1, &l2);
  for (i = 0; i < n; i++) scanf("%d", &a[i].first.first);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].first.second);
    a[i].second = i + 1;
  }
  sort(a, a + n);
  printf("%d\n", dp(0, l2));
  prnt(0, l2);
  printf("%d", ls[1][0]);
  for (i = 1; i < l1; i++) printf(" %d", ls[1][i]);
  printf("\n%d", ls[0][0]);
  for (i = 1; i < l1; i++) printf(" %d", ls[0][i]);
  puts("");
  return 0;
}
