#include <bits/stdc++.h>
using namespace std;
typedef int matrix[130][130];
long long n;
vector<int> v[30];
int k, q[30], d, f[30], h[130], len[30], r[30], ans;
matrix a, b, t;
char c;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void mul(matrix a, matrix b) {
  for (int i = 0; i < len[0]; i++)
    for (int j = 0; j < len[0]; j++) {
      t[i][j] = 0;
      for (int k = 0; k < len[0]; k++)
        t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % 12345;
    }
  for (int i = 0; i < len[0]; i++)
    for (int j = 0; j < len[0]; j++) a[i][j] = t[i][j];
}
void pow(long long n) {
  for (int i = 0; i < len[0]; i++) a[i][i] = 1;
  for (int i = 0; n >> i; i++) {
    if ((n >> i) & 1) mul(a, b);
    mul(b, b);
  }
}
int main() {
  scanf("%I64d%d", &n, &k);
  for (int i = 0; i < 26; i++) q[i] = 1;
  for (int i = 0; i < k; i++)
    scanf(" %c%d", &c, &d), c -= 'A', q[c] *= d / gcd(d, q[c]),
        f[c] = 1, v[c].push_back(d);
  len[26] = 1;
  for (int j = 25; j >= 0; j--) len[j] = len[j + 1] * q[j];
  for (int j = 0; j < len[0]; j++) {
    for (int i = 0; i < 26; i++) r[i] = j / len[i + 1] % q[i];
    h[j] = 1;
    for (int i = 0; i < 26; i++)
      if (v[i].size()) {
        bool fg = 0;
        for (int d : v[i]) fg |= (r[i] % d == 0);
        h[j] &= fg;
      }
    for (int i = 0; i < 26; i++)
      if (f[i])
        b[j][(r[i] + 1 == q[i]) ? j + len[i + 1] - len[i] : j + len[i + 1]]++;
  }
  pow(n);
  for (int i = 0; i < len[0]; i++) ans += h[i] * a[0][i];
  printf("%d\n", ans);
}
