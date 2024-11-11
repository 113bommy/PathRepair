#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[50][50];
int a, b;
int g, h;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  cin >> a >> b;
  g = a * b;
  if (a <= n && b <= m)
    for (int i = 0; i <= n - a; i++)
      for (int j = 0; j <= m - b; j++) {
        h = 0;
        for (int k = i; k < i + a; k++)
          for (int l = j; l < j + b; l++) h += c[k][l];
        g = min(g, h);
      }
  if (a <= n && b <= m)
    for (int i = 0; i <= m - a; i++)
      for (int j = 0; j <= n - b; j++) {
        h = 0;
        for (int k = i; k < i + a; k++)
          for (int l = j; l < j + b; l++) h += c[l][k];
        g = min(g, h);
      }
  cout << g;
  return 0;
}
