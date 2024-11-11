#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0) + (size_t) new char);
inline int add(int a, int b, int mod) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b, int mod) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b, int mod) { return (long long)a * b % mod; }
inline int power(int a, int b, int mod) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a, mod);
    a = mult(a, a, mod);
    b >>= 1;
  }
  return out;
}
int n, m;
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (!(x % i)) return 0;
  return 1;
}
vector<int> A;
int R[1048576], Rlen;
vector<int> D[25];
void ntt(vector<int> &A, int len, int mod, int G) {
  if (Rlen != len) {
    Rlen = len;
    for (int i = 0; i < (1 << len); i++)
      R[i] = R[i >> 1] >> 1 | ((i & 1) << (len - 1));
  }
  for (int i = 0; i < (1 << len); i++)
    if (i < R[i]) swap(A[i], A[R[i]]);
  for (int i = 1; i < (1 << len); i <<= 1) {
    int w = power(G, (mod - 1) / (i << 1), mod);
    for (int j = 0; j < (1 << len); j += (i << 1)) {
      int t = 1;
      for (int k = 0; k < i; k++, t = mult(t, w, mod)) {
        int tx = A[j + k], ty = mult(A[i + j + k], t, mod);
        A[j + k] = add(tx, ty, mod);
        A[i + j + k] = dec(tx, ty, mod);
      }
    }
  }
}
int check(int v) {
  if (!isprime(v)) return -1;
  if (v <= 3) return -1;
  int ph = v - 1;
  int d = 0;
  while (!((ph >> d) & 1)) d++;
  vector<int> dat;
  if ((1 << d) < n)
    dat = D[d];
  else
    dat = A;
  for (auto &x : dat) x = (x % v + v) % v;
  dat.resize(1 << d);
  int g = rnd() % ph + 1;
  while (power(g, ph >> 1, v) == 1) g = rnd() % ph + 1;
  ntt(dat, d, v, g);
  g = power(g, (v - 1) / (1 << d), v);
  for (int i = 0, t = 1; i < (1 << d); i++, t = mult(t, g, v))
    if (t >= 2 && t < ph && !dat[i]) return t;
  return -1;
}
char str[100010];
int main() {
  scanf("%d%d", &n, &m);
  A.resize(n);
  scanf("%s", str);
  for (int i = 0; i < n; i++) A[i] += str[i];
  scanf("%s", str);
  for (int i = 0; i < n; i++) A[i] -= str[i];
  for (int i = 0; (1 << i) < n; i++) {
    D[i].resize(1 << i);
    for (int j = 0; j < n; j++) D[i][j % (1 << i)] += A[j];
  }
  while (1) {
    int ret = check(m);
    if (ret != -1) {
      printf("%d %d\n", m, ret);
      return 0;
    }
    m++;
  }
  return 0;
}
