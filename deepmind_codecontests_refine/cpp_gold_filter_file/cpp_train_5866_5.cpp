#include <bits/stdc++.h>
using namespace std;
int n, m, tot, dl1[3010 * 3], dl2[3010 * 3], fr[3010 * 3];
double ans, p[3010][310], a[3010 * 3][3010], b[3010 * 3];
struct pr {
  int x;
  double y;
  bool friend operator<(pr a, pr b) {
    if (a.y == b.y)
      return a.x < b.x;
    else
      return a.y > b.y;
  }
} P;
set<pr> s;
inline void cal() {
  int x = dl1[tot];
  for (int i = (1); i <= (n); i++)
    a[tot][i] = a[tot][i - 1] * (1 - p[i][x]) + a[fr[tot]][i - 1] * p[i][x];
  b[tot] = b[fr[tot]] + a[tot][n];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      scanf("%lf", &p[i][j]);
      p[i][j] /= 1000;
    }
  for (int i = (1); i <= (m); i++) {
    dl1[i] = i;
    dl2[i] = 1;
    a[i][0] = 1;
    tot++;
    cal();
    P.x = i;
    P.y = 1 - b[i];
    s.insert(P);
  }
  for (int i = (1); i <= (n); i++) {
    P = *s.begin();
    s.erase(s.begin());
    ans += P.y;
    tot++;
    fr[tot] = P.x;
    dl1[tot] = dl1[P.x];
    dl2[tot] = dl2[P.x] + 1;
    cal();
    P.x = tot;
    P.y = 1 - b[tot];
    s.insert(P);
  }
  printf("%.12lf\n", ans);
}
