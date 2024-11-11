#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const { return y < a.y; };
};
int a, b, c, d, i, k, n, m, e, dx[10] = {1, 0, -1, 0, 1, 1, -1, -1},
                               dy[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int o[251][252][251];
int l[251][251][506], v[555];
int j[1];
long long x, y, z[33], mod = 998244353, mm = 1000000009;
char r[331][333];
P u[1];
queue<int> q;
map<long long, int> p;
bool as(P a, P b) { return a.y > b.y; }
int main() {
  z[0] = 1;
  for (int t = 1; t < 26; t++) z[t] = z[t - 1] * 26 % mm;
  scanf("%d %d", &a, &b);
  for (int t = 1; t <= a; t++) {
    scanf("%s", r[t] + 1);
    for (int w = 1; w <= b; w++) r[t][w] -= 'a';
  }
  m = 0;
  vector<int> v1;
  v1.resize(26);
  for (int t = 1; t <= a; t++)
    for (int i = 1; i <= b; i++) {
      long long x = 0;
      n = 0;
      for (int j = i; j <= b; j++) {
        x += z[r[t][j]];
        x %= mm;
        v1[r[t][j]]++;
        if (v1[r[t][j]] % 2)
          n++;
        else
          n--;
        if (n <= 1 && p[x] == 0) p[x] = ++e;
        if (n <= 1)
          o[t][i][j] = p[x];
        else
          o[t][i][j] = --m;
      }
      for (int h = 0; h < 26; v1[h] = 0, h++)
        ;
    }
  for (int i = 1; i <= b; i++)
    for (int j = i; j <= b; j++) {
      for (int t = 1; t <= a; t++) {
        v[t * 2 - 1] = o[t][i][j];
        if (t < a) v[t * 2] = 0;
      }
      n = m = 0;
      for (int h = 1; h <= a * 2 - 1; h++) {
        if (n >= h) l[i][j][h] = min(n - h, l[i][j][m - (h - m)]);
        for (; h - l[i][j][h] > 1 && h + l[i][j][h] + 1 <= a * 2 - 1;
             l[i][j][h]++)
          if (v[h - l[i][j][h] - 1] != v[h + l[i][j][h] + 1]) break;
        if (v[h] == 0)
          y += (l[i][j][h] + 1) / 2;
        else if (v[h] > 0)
          y += l[i][j][h] / 2 + 1;
        if (h + l[i][j][h] > n) n = l[i][j][h] + h, m = h;
      }
      x += y;
      y = 0;
    }
  printf("%lld", x);
}
