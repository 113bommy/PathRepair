#include <bits/stdc++.h>
using namespace std;
int bigp;
long long maxc, l, r, k;
vector<long long> f;
struct matrix {
  int a1, a2, b1, b2;
};
matrix m_m(int a, int b, int c, int d) {
  matrix f;
  f.a1 = a;
  f.a2 = b;
  f.b1 = c;
  f.b2 = d;
  return f;
}
matrix times(matrix a, matrix b) {
  matrix c;
  c.a1 = ((long long)a.a1 * b.a1 + (long long)a.b1 * b.a2) % bigp;
  c.a2 = ((long long)a.a2 * b.a1 + (long long)a.b2 * b.a2) % bigp;
  c.b1 = ((long long)a.a1 * b.b1 + (long long)a.b1 * b.b2) % bigp;
  c.b2 = ((long long)a.a2 * b.b1 + (long long)a.b2 * b.b2) % bigp;
  return c;
}
int getnthfibonacci(long long n) {
  --n;
  matrix fc = m_m(0, 1, 1, 1), dw = m_m(1, 0, 0, 1), g2, v2[70];
  long long x, tc;
  v2[0] = fc;
  for (int i = 1; i <= 69; i++) v2[i] = times(v2[i - 1], v2[i - 1]);
  g2 = dw;
  tc = 62;
  x = n;
  while (x > 0) {
    while (x < ((long long)1 << tc)) --tc;
    g2 = times(g2, v2[tc]);
    x -= (long long)1 << tc;
  }
  return g2.b2 % bigp;
}
long long check(long long l, long long r, long long s) {
  if (s == 0) return -1;
  return (r / s) - ((l - 1) / s + 1) + 1;
}
int main() {
  cin >> bigp >> l >> r >> k;
  for (int i = 1; (long long)i * i <= l; i++) {
    f.push_back(i);
    f.push_back(l / i);
    f.push_back(l / i + 1);
    f.push_back(l / i - 1);
  }
  for (int i = 1; (long long)i * i <= r; i++) {
    f.push_back(i);
    f.push_back(r / i);
    f.push_back(r / i + 1);
    f.push_back(r / i - 1);
  }
  maxc = 0;
  for (int i = 0; i < f.size(); i++)
    if (check(l, r, f[i]) >= k) maxc = max(maxc, f[i]);
  cout << getnthfibonacci(maxc) << endl;
  return 0;
}
