#include <bits/stdc++.h>
using namespace std;
char A[1005][1005];
pair<char, int> p[1005][1005];
int n, m, len;
long long x;
int f, g;
char c;
void solve() {
  for (int j = 1; j <= m; j++) {
    len = 0;
    for (int i = 1; i <= n;) {
      f = i;
      c = A[i][j];
      while (i <= n && A[i][j] == c) {
        len++;
        i++;
      }
      while (len) {
        p[f][j].first = c;
        p[f][j].second = len;
        len--;
        f++;
      }
    }
  }
}
bool shu(int a, int b) {
  if (a + len <= n && a - len >= 1 && p[a + len][b].second >= len &&
      p[a - len][b].second >= len && p[a + len][b].first != c &&
      p[a - len][b].first != c) {
    return 1;
  }
  return 0;
}
bool color(int a, int b) {
  if (p[a + len][b].first == p[a + len][b + 1].first &&
      p[a - len][b].first == p[a - len][b + 1].first &&
      p[a][b].first == p[a][b + 1].first)
    return 1;
  return 0;
}
bool heng(int a, int b) {
  if (b + 1 <= m && shu(a, b + 1) && p[a][b + 1].second == len) {
    if (color(a, b)) {
      return 1;
    }
    return 0;
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", &A[i][1]);
  }
  solve();
  for (int i = 2; i < n; i++) {
    for (int j = 1; j <= m;) {
      c = p[i][j].first;
      len = p[i][j].second;
      if (shu(i, j)) {
        g = 1;
        x = x + 1;
        while (j <= m && heng(i, j)) {
          g++;
          x = x + g;
          j++;
        }
      }
      j++;
    }
  }
  cout << x << endl;
}
