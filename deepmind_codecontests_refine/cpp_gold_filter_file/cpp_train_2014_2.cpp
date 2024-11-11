#include <bits/stdc++.h>
using namespace std;
long long ms[2][1000];
long long rs[1000];
int cnt[2];
long long tmp[2][2];
long long r[2][2];
long long m[2][2];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mlt(long long a, long long b) {
  long long r = 0LL;
  while (b) {
    if (b & 1LL) r = (r + a) % 10000000000000LL;
    a = (a + a) % 10000000000000LL;
    b >>= 1LL;
  }
  return r % 10000000000000LL;
}
void mult(long long a[2][2], long long b[2][2], long long c[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tmp[i][j] = 0;
      for (int z = 0; z < 2; z++)
        tmp[i][j] = (tmp[i][j] + mlt(a[i][z], b[z][j])) % 10000000000000LL;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) c[i][j] = tmp[i][j];
  }
}
void exp(long long e, long long m[2][2], long long tp[2][2]) {
  memset(r, 0, sizeof(r));
  r[0][0] = r[1][1] = 1LL;
  while (e) {
    if (e & 1LL) mult(r, m, r);
    mult(m, m, m);
    e >>= 1LL;
  }
  tp[0][0] = r[0][0];
  tp[0][1] = r[0][1];
  tp[1][0] = r[1][0];
  tp[1][1] = r[1][1];
}
long long fib(long long p) {
  m[0][0] = 0;
  m[1][1] = m[0][1] = m[1][0] = 1LL;
  exp(p - 1LL, m, m);
  return r[1][1];
}
int main() {
  long long f;
  cin >> f;
  int cnt[2];
  cnt[0] = cnt[1] = 0;
  long long l[2];
  l[0] = 8192LL;
  l[1] = 1953125LL;
  long long v[2];
  v[0] = f % l[0];
  v[1] = f % l[1];
  long long tm[2];
  for (int j = 0; j < 2; j++) {
    long long a = 0, b = 1, t;
    for (int i = 0; true; i++) {
      if (a == v[j]) ms[j][cnt[j]++] = i;
      t = b;
      b = (a + b) % l[j];
      a = t;
      if (a == 0 && b == 1LL) {
        tm[j] = i + 1;
        break;
      }
    }
  }
  int cn = 0;
  int ii, jj;
  long long tot = (tm[0] / gcd(tm[0], tm[1]));
  long long cic = tot * tm[1];
  for (int i = 0; i < cnt[0]; i++) {
    for (int j = 0; j < cnt[1]; j++) {
      ii = ms[0][i];
      jj = ms[1][j];
      for (long long y = 0; y <= tot; y++) {
        if ((jj - ii + y * tm[1]) % tm[0] == 0) {
          rs[cn++] = jj + y * tm[1];
        }
      }
    }
  }
  long long resp = -1LL;
  long long m[2][2];
  long long m2[2][2];
  long long qtd = (15000000000000LL + cic - 1LL) / cic;
  for (int i = 0; i < cn; i++) {
    long long v = rs[i];
    m[0][0] = m2[0][0] = 0;
    m[1][1] = m[1][0] = m[0][1] = m2[1][1] = m2[1][0] = m2[0][1] = 1LL;
    exp(v - 1, m, m);
    exp(cic, m2, m2);
    int u = 0;
    for (int j = 0; j <= qtd; j++) {
      u++;
      if (m[1][1] == f) {
        if (resp == -1LL)
          resp = cic * j + v;
        else
          resp = min(resp, cic * j + v);
        break;
      }
      mult(m, m2, m);
    }
  }
  cout << resp << endl;
  return 0;
}
