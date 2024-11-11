#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y, z;
  bool operator<(const P &a) const { return x > a.x; }
};
int a, b, c, i, k, o[3][800002], n, m, d, e,
    dy[15] = {0, 0, -1, 1, -1, 1, -1, 1}, dx[15] = {-1, 1, 0, 0, 1, 1, -1, -1};
int l[100100];
long long x, y, z, v1, v2;
P u[200600];
int j[60];
queue<int> q, q1;
stack<int> s;
map<int, int> p;
string r, r1, r2;
bool as(int a, int b) { return a > b; }
int f(int h, int t, int w) {
  int u = 0;
  for (; t < w;) {
    if (t % 2)
      u = max(u, o[h][t]), t++;
    else if (w % 2 == 0)
      u = max(u, o[h][w]), w--;
    else
      t /= 2, w /= 2;
  }
  return max(u, o[h][t]);
}
int main() {
  scanf("%d %d %d", &a, &l[0], &l[1]);
  for (i = 1; i < 100000; i <<= 1)
    ;
  for (int t = 1; t <= a; t++) {
    scanf("%d %d %c", &n, &m, &d);
    if (o[d - 67][m + i - 1]) {
      if (m * 2 <= l[d - 67]) k = max(k, o[d - 67][m + i - 1] + n);
      o[d - 67][m + i - 1] = max(o[d - 67][m + i - 1], n);
    } else
      o[d - 67][m + i - 1] = n;
    if (m <= l[d - 67]) l[d - 65] = max(l[d - 65], n);
  }
  if (l[2] && l[3]) k = max(k, l[2] + l[3]);
  for (int h = 0; h < 2; h++)
    for (int t = i - 1; t > 0; t--) o[h][t] = max(o[h][t * 2], o[h][t * 2 + 1]);
  for (int h = 0; h < 2; h++) {
    for (int t = l[h] - 1; t > 1; t--) {
      if (o[h][t + i - 1] && f(h, i, min(t + i - 2, i + l[h] - t - 1)))
        k = max(k, o[h][t + i - 1] + f(h, i, min(t + i - 2, i + l[h] - t - 1)));
    }
  }
  printf("%d", k);
}
