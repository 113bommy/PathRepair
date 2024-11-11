#include <bits/stdc++.h>
using namespace std;
const long long kN = 10000000000000LL;
const int kMod[2] = {8192, 1953125};
const int kRange[2] = {12288, 7812500};
long long x;
int mod[2];
vector<int> pos[2];
inline long long Mul(long long a, long long b) {
  if (a < b) swap(a, b);
  long long res = 0;
  while (b) {
    if (b & 1) {
      (res) += (a);
      if ((res) >= kN) (res) -= kN;
    };
    b >>= 1;
    {
      (a) += (a);
      if ((a) >= kN) (a) -= kN;
    };
  }
  return res;
}
struct Matrix {
  long long v[2][2];
  void clear() { memset(v, 0, sizeof(v)); }
  Matrix() { clear(); }
} e, f, a;
Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0; i < 2; ++i)
    for (int k = 0; k < 2; ++k)
      if (a.v[i][k])
        for (int j = 0; j < 2; ++j) {
          (c.v[i][j]) += (Mul(a.v[i][k], b.v[k][j]));
          if ((c.v[i][j]) >= kN) (c.v[i][j]) -= kN;
        };
  return c;
}
Matrix PowerMod(const Matrix &a, long long b) {
  Matrix res = e, tmp = a;
  while (b) {
    if (b & 1) res = res * tmp;
    b >>= 1;
    tmp = tmp * tmp;
  }
  return res;
}
vector<int> Find(int rest, int mod, int range) {
  vector<int> res;
  int a = 0, b = 1, p = 0;
  while (p < range) {
    if (a == rest) res.push_back(p);
    int c = (a + b) % mod;
    a = b, b = c;
    ++p;
  }
  return res;
}
long long Calc(long long y) {
  a.clear();
  a.v[0][0] = 0;
  a.v[1][0] = 1;
  a = PowerMod(f, y) * a;
  return a.v[0][0];
}
int main() {
  scanf("%I64d", &x);
  for (int i = 0; i < 2; ++i) {
    mod[i] = x % kMod[i];
    pos[i] = Find(mod[i], kMod[i], kRange[i]);
    if (pos[i].size() == 0) {
      puts("-1");
      return 0;
    }
  }
  e.v[0][0] = e.v[1][1] = 1;
  f.v[0][1] = f.v[1][0] = f.v[1][1] = 1;
  long long ans = LONG_LONG_MAX;
  for (int i = 0; i < int(pos[0].size()); ++i)
    for (int j = 0; j < int(pos[1].size()); ++j)
      for (long long p = 0; p < 1000000; ++p) {
        long long t = p * kRange[1] + pos[1][j] - pos[0][i];
        if (t >= ans) break;
        if (t >= 0 && t % kRange[0] == 0) {
          t += pos[0][i];
          if (Calc(t) == x) {
            ans = min(ans, t);
            break;
          }
        }
      }
  printf("%I64d\n", ans);
  return 0;
}
