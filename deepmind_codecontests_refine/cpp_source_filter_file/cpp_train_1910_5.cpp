#include <bits/stdc++.h>
using namespace std;
struct Line {
  int a, b;
  long long c;
};
int n, m, v[1000005];
pair<int, int> p[300];
Line getLine(pair<int, int> A, pair<int, int> B) {
  Line res;
  res.a = A.second - B.second;
  res.b = B.first - A.first;
  res.c = 1LL * res.a * A.first + 1LL * res.b * A.second;
  return res;
}
double intersectLineWithOx(Line l) {
  if (!l.a) return 0;
  return ((double)l.c) / l.a;
}
bool onLine(pair<int, int> P, Line l) {
  return 1LL * P.first * l.a + 1LL * P.second * l.b == l.c;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d %d", &p[i].first, &p[i].second);
  for (int i = 1; i <= n; i++) v[i] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++) {
      Line l = getLine(p[i], p[j]);
      int xx = floor(intersectLineWithOx(l) + 0.5);
      if (!onLine(make_pair(xx, 0), l) || xx < 1 || xx > n) continue;
      int cnt = 2;
      for (int k = j + 1; k <= m; k++)
        if (onLine(p[k], l)) ++cnt;
      v[xx] = (((v[xx]) > (cnt)) ? (v[xx]) : (cnt));
    }
  int sol = 0;
  for (int i = 1; i <= m; i++) sol += v[i];
  printf("%d\n", sol);
  return 0;
}
