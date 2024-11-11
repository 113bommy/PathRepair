#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  bool ar[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ar[i][j];
  int a, b;
  cin >> a >> b;
  int m1 = 56, c = 0;
  for (int i = 0; i < n - a + 1; i++)
    for (int j = 0; j < m - b + 1; j++) {
      for (int i1 = 0; i1 < a; i1++)
        for (int j1 = 0; j1 < b; j1++)
          if (ar[i + i1][j + j1]) c++;
      m1 = min(m1, c);
      c = 0;
    }
  for (int i = 0; i < n - b + 1; i++)
    for (int j = 0; j < m - a + 1; j++) {
      for (int i1 = 0; i1 < a; i1++)
        for (int j1 = 0; j1 < b; j1++)
          if (ar[i + j1][j + i1]) c++;
      m1 = min(m1, c);
      c = 0;
    }
  cout << m1;
}
