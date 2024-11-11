#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int x[(50 + 1)][(50 + 1)];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> x[i][j];
  cin >> a >> b;
  int min = n * m + 1;
  for (int i = 0; i < n - a + 1; i++, cout << endl)
    for (int j = 0; j < m - b + 1; j++) {
      int t = 0;
      for (int k = i; k < i + a; k++)
        for (int l = j; l < j + b; l++)
          if (x[k][l]) t++;
      min = std::min(min, t);
    }
  for (int i = 0; i < n - a + 1; i++, cout << endl)
    for (int j = 0; j < m - b + 1; j++) {
      int t = 0;
      for (int k = i; k < i + b; k++)
        for (int l = j; l < j + a; l++)
          if (x[k][l]) t++;
      min = std::min(min, t);
    }
  cout << min << endl;
  return 0;
}
