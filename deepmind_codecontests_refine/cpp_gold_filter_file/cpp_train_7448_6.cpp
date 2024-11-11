#include <bits/stdc++.h>
using namespace std;
int compare(const void* x1, const void* x2) { return (*(int*)x1 - *(int*)x2); }
double eps = 0.0001;
int main() {
  char mas[100][100];
  int n, m;
  char c;
  set<char> s;
  cin >> n >> m >> c;
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (m); ++j) cin >> mas[i][j];
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (m); ++j)
      if (mas[i][j] == c) {
        if (i > 0)
          if (mas[i - 1][j] != c && mas[i - 1][j] != '.')
            s.insert(mas[i - 1][j]);
        if (i < n - 1)
          if (mas[i + 1][j] != c && mas[i + 1][j] != '.')
            s.insert(mas[i + 1][j]);
        if (j > 0)
          if (mas[i][j - 1] != c && mas[i][j - 1] != '.')
            s.insert(mas[i][j - 1]);
        if (j < m - 1)
          if (mas[i][j + 1] != c && mas[i][j + 1] != '.')
            s.insert(mas[i][j + 1]);
      }
  cout << s.size();
  return 0;
}
