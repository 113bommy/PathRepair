#include <bits/stdc++.h>
using namespace std;
const int maxn = 501;
int a, b, c, d, e;
int m[maxn][maxn];
int n[maxn][maxn];
int f[maxn][maxn];
int ans[maxn][maxn];
void print(int m[maxn][maxn]) {
  for (int i = 0; i < a; ++i) {
    for (int q = 0; q < a; ++q) cout << m[i][q] << ' ';
    cout << "\n";
  }
}
int main() {
  for (int i = 0; i < maxn; ++i)
    for (int q = 0; q < maxn; ++q) m[i][q] = 1E9, n[i][q] = 5E8;
  for (int i = 0; i < maxn; ++i) m[i][i] = 0;
  cin >> a >> b;
  for (int i = 0; i < b; ++i) {
    cin >> c >> d >> e;
    --c, --d;
    m[c][d] = m[d][c] = e;
    n[c][d] = n[d][c] = e;
  }
  for (int k = 0; k < a; ++k)
    for (int i = 0; i < a; ++i)
      for (int q = 0; q < a; ++q)
        if (m[i][q] > m[i][k] + m[k][q]) m[i][q] = m[i][k] + m[k][q];
  for (int i = 0; i < a; ++i)
    for (int q = 0; q < a; ++q)
      for (int k = 0; k < a; ++k)
        if (m[i][k] + n[k][q] == m[i][q]) f[i][q]++;
  for (int i = 0; i < a; ++i)
    for (int q = 0; q < a; ++q)
      for (int k = 0; k < a; ++k)
        if (m[i][k] + m[k][q] == m[i][q]) ans[i][q] += f[i][k];
  for (int i = 0; i < a; ++i)
    for (int q = i + 1; q < a; ++q) {
      printf("%d ", ans[i][q]);
    }
  return 0;
}
