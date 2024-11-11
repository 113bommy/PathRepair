#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = (int)1e9;
const double inf1 = 1e-9;
const int ss = (int)1e6 + 3;
bool pred(const pair<string, pair<int, vector<int> > >& i,
          const pair<string, pair<int, vector<int> > >& j) {
  return i.second.first > j.second.first;
}
char x[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char y[2] = {'z', 'y'};
int main() {
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  int n1 = n;
  int m1 = m;
  if ((n * m) % 2 == 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  if (n % 2 == 1) {
    --n;
    a -= m / 2;
    if (a < 0) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  if (m % 2 == 1) {
    --m;
    b -= n / 2;
    if (b < 0) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  if (a % 2 == 1) --a;
  if (b % 2 == 1) --b;
  if (n * m > 2 * a + 2 * b + 4 * c) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  vector<vector<char> > mas(n1, vector<char>(m1));
  int k = 4;
  for (int i = 0; i < n; i += 2) {
    int j = 0;
    if (k == 0)
      k = 4;
    else
      k = 0;
    int l = 0;
    while (j < m) {
      if (c > 0) {
        --c;
        mas[i][j] = x[l + k];
        mas[i][j + 1] = x[l + k];
        mas[i + 1][j] = x[l + k];
        mas[i + 1][j + 1] = x[l + k];
        ++l;
        l %= 4;
        j += 2;
        continue;
      }
      if (b > 1) {
        b -= 2;
        mas[i][j] = x[l + k];
        mas[i + 1][j] = x[l + k];
        ++l;
        l %= 4;
        mas[i][j + 1] = x[l + k];
        mas[i + 1][j + 1] = x[l + k];
        ++l;
        l %= 4;
        j += 2;
        continue;
      }
      if (a > 1) {
        a -= 2;
        mas[i][j] = x[l + k];
        mas[i][j + 1] = x[l + k];
        ++l;
        l %= 4;
        mas[i + 1][j] = x[l + k];
        mas[i + 1][j + 1] = x[l + k];
        ++l;
        l %= 4;
        j += 2;
        continue;
      }
    }
  }
  if (n1 % 2 == 1) {
    int k = 0;
    for (int i = 0; i < m; i += 2) {
      mas[n][i] = y[k];
      mas[n][i + 1] = y[k];
      ++k;
      k %= 2;
    }
  }
  if (m1 % 2 == 1) {
    int k = 0;
    for (int i = 0; i < n; i += 2) {
      mas[i][m] = y[k];
      mas[i + 1][m] = y[k];
      ++k;
      k %= 2;
    }
  }
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < m1; ++j) cout << mas[i][j];
    cout << endl;
  }
  return 0;
}
