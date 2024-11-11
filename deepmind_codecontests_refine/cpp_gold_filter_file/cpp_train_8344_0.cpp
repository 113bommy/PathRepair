#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b, long long c) {
  long long v = 1;
  for (; b; b >>= 1, a = a * a % c)
    if (b & 1) v = v * a % c;
  return v;
}
long long inv(long long x, long long mod) { return qpow(x, mod - 2, mod); }
int test = 1;
const int maxn = 5 + 1e5;
long long n, f1, f2, f3, c;
long long m1[5][5];
long long m2[5][5];
void mul(long long a[][5], long long b[][5], int len) {
  long long temp[5][5];
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      temp[i][j] = 0;
      for (int k = 0; k < len; k++) {
        temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % (1000000007 - 1);
      }
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      a[i][j] = temp[i][j];
    }
  }
  return;
}
long long res[5][5];
void mqpow(long long a[][5], long long b, int len) {
  memset(res, 0, sizeof(res));
  for (int i = 0; i < len; i++) res[i][i] = 1;
  while (b) {
    if (b & 1) mul(res, a, len);
    mul(a, a, len);
    b >>= 1;
  }
  return;
}
int main() {
  memset(m1, 0, sizeof(m1));
  m1[0][0] = m1[0][1] = m1[0][2] = m1[0][3] = m1[0][4] = 1;
  m1[1][0] = m1[2][1] = m1[3][3] = m1[3][4] = m1[4][4] = 1;
  while (test--) {
    long long ans = 0;
    cin >> n >> f1 >> f2 >> f3 >> c;
    mqpow(m1, n - 3, 5);
    ans = res[0][4] * 2 % (1000000007 - 1);
    ans = qpow(c, ans, 1000000007);
    long long t;
    memset(m2, 0, sizeof(m2));
    m2[0][0] = m2[0][1] = m2[0][2] = m2[1][0] = m2[2][1] = 1;
    mqpow(m2, n - 3, 3);
    t = (res[0][2]) % (1000000007 - 1);
    ans = (ans * qpow(f1, t, 1000000007)) % 1000000007;
    memset(m2, 0, sizeof(m2));
    m2[0][0] = m2[0][1] = m2[0][2] = m2[1][0] = m2[2][1] = 1;
    mqpow(m2, n - 3, 3);
    t = (res[0][1]) % (1000000007 - 1);
    ans = (ans * qpow(f2, t, 1000000007)) % 1000000007;
    memset(m2, 0, sizeof(m2));
    m2[0][0] = m2[0][1] = m2[0][2] = m2[1][0] = m2[2][1] = 1;
    mqpow(m2, n - 3, 3);
    t = (res[0][0]) % (1000000007 - 1);
    ans = (ans * qpow(f3, t, 1000000007)) % 1000000007;
    cout << ans << endl;
  }
  return 0;
}
