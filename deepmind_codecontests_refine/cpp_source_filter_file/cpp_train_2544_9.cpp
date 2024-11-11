#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const unsigned long long INF64 = 3e18;
const long double EPS = 1e-12;
const long double PI = 3.1415926535897932384620;
const unsigned long long MD = 925262732;
const unsigned long long T = 634521;
const int N = 300101;
const int M = 1010;
const int MAGIC = 4000;
int n, m, a[M][M], b[M][M];
string s;
void er() {
  cout << 0;
  exit(0);
}
bool check(int first, int second, int z) {
  return (!(first >= 0 && first < n && second >= 0 && second < m) ||
          b[first][second] != z);
}
void get() {
  for (int first = 0; first < int(n); first++)
    for (int second = 0; second < int(m); second++)
      if (!check(first + 1, second, b[first][second]) ||
          !check(first + 1, second + 1, b[first][second]) ||
          !check(first, second + 1, b[first][second]))
        return;
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) cout << b[i][j];
    cout << endl;
  }
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) {
    cin >> s;
    for (int j = 0; j < int(m); j++) a[i][j] = b[i][j] = s[j] - '0';
  }
  for (int x1 = 1; x1 <= 4; x1++)
    for (int x2 = 1; x2 <= 4; x2++)
      if (x1 != x2)
        for (int y1 = 1; y1 <= 4; y1++)
          for (int y2 = 1; y2 <= 4; y2++)
            if (y1 != y2 && x1 != y1 && x2 != y1 && x1 != y2 && x2 != y2) {
              for (int i = 0; i < int(n); i++)
                for (int j = 0; j < int(m); j++) b[i][j] = a[i][j];
              for (int i = 0; i < int(n); i++) {
                int q = -1;
                for (int j = 0; j < int(m); j++)
                  if (a[i][j] != 0) q = j;
                if (q == -1) q = m;
                if (i & 1) {
                  for (int j = q + 1; j < m; j++)
                    if (b[i][j] == 0)
                      if (b[i][j - 1] == x1)
                        b[i][j] = x2;
                      else
                        b[i][j] = x1;
                  for (int j = q - 1; j >= 0; j--)
                    if (b[i][j] == 0)
                      if (b[i][j + 1] == x1)
                        b[i][j] = x2;
                      else
                        b[i][j] = x1;
                } else {
                  for (int j = q + 1; j < m; j++)
                    if (b[i][j] == 0)
                      if (b[i][j - 1] == y1)
                        b[i][j] = y2;
                      else
                        b[i][j] = y1;
                  for (int j = q - 1; j >= 0; j--)
                    if (b[i][j] == 0)
                      if (b[i][j + 1] == y1)
                        b[i][j] = y2;
                      else
                        b[i][j] = y1;
                }
              }
              get();
              for (int i = 0; i < int(n); i++)
                for (int j = 0; j < int(m); j++) b[i][j] = a[i][j];
              for (int j = 0; j < int(m); j++) {
                int q = -1;
                for (int i = 0; i < int(n); i++)
                  if (a[i][j] != 0) q = i;
                if (q == -1) q = n;
                if (j & 1) {
                  for (int i = q + 1; i < m; i++)
                    if (b[i][j] == 0)
                      if (b[i - 1][j] == x1)
                        b[i][j] = x2;
                      else
                        b[i][j] = x1;
                  for (int i = q - 1; i >= 0; i--)
                    if (b[i][j] == 0)
                      if (b[i + 1][j] == x1)
                        b[i][j] = x2;
                      else
                        b[i][j] = x1;
                } else {
                  for (int i = q + 1; i < m; i++)
                    if (b[i][j] == 0)
                      if (b[i - 1][j] == y1)
                        b[i][j] = y2;
                      else
                        b[i][j] = y1;
                  for (int i = q - 1; i >= 0; i--)
                    if (b[i][j] == 0)
                      if (b[i + 1][j] == y1)
                        b[i][j] = y2;
                      else
                        b[i][j] = y1;
                }
              }
              get();
            }
  cout << 0;
  return 0;
}
