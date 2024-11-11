#include <bits/stdc++.h>
using namespace std;
template <class T>
string ToString(T t) {
  stringstream s;
  s << t;
  return s.str();
}
template <class T>
void ToOther(T &t, string a) {
  stringstream s(a);
  s >> t;
}
long long n, k, l, mod;
int A[4][4] = {
    {1, 1, 0, 0},
    {1, 0, 0, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
};
void sum(int &r, int x) {
  r += x;
  if (r >= mod) r -= mod;
}
int mul(int a, int b) { return (long long)a * b % mod; }
void MUL(int a[4][4], int b[4][4]) {
  int r[4][4] = {0};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) sum(r[i][j], mul(a[i][k], b[k][j]));
  memcpy(a, r, sizeof(r));
}
void POW(int a[4][4], long long y) {
  int r[4][4] = {0};
  for (int i = 0; i < 4; i++) r[i][i] = 1;
  while (y) {
    if (y & 1) MUL(r, a);
    MUL(a, a);
    y /= 2;
  }
  memcpy(a, r, sizeof(r));
}
int main() {
  cin >> n >> k >> l >> mod;
  POW(A, n);
  long long zero = (A[0][0] + A[0][1]) % mod;
  long long one = (A[0][2] + A[0][3]) % mod;
  long long r = 1;
  for (int i = 0; i <= l; i++) {
    if (k >> i & 1) {
      r = mul(r, one);
      k ^= (1ll << i);
    } else {
      r = mul(r, zero);
    }
  }
  if (k) r = 0;
  cout << r << endl;
}
