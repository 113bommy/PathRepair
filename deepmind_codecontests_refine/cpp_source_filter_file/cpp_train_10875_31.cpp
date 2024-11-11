#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926536;
int main() {
  int n, m;
  cin >> n >> m;
  int s[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  int a, b;
  cin >> a >> b;
  int min = 10000000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (n - i > b && n - j > a) {
        int c = 0;
        for (int k = i; k < i + b; k++)
          for (int l = j; l < j + a; l++)
            if (s[k][l] == 1) c++;
        if (c < min) min = c;
      }
      if (n - i >= a && n - j >= b) {
        int c = 0;
        for (int k = i; k < i + a; k++)
          for (int l = j; l < j + b; l++)
            if (s[k][l] == 1) c++;
        if (c < min) min = c;
      }
    }
  cout << min;
}
