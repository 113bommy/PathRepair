#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 101;
int n, q, c, result[N], cum[M][M], x[N], y[N], s[N];
struct Query {
  int t, x1, y1, x2, y2, i;
  bool operator<(Query a) const { return t < a.t; }
} query[N];
void doStuff(int t) {
  memset(cum, 0, sizeof cum);
  for (int i = 0; i < n; ++i) {
    cum[x[i]][y[i]] += (s[i] + t) % (c + 1);
  }
  for (int i = 1; i < M; ++i) {
    for (int j = 1; j < M; ++j) {
      cum[i][j] += cum[i][j - 1];
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &q, &c);
  for (int i = 0; i < n; ++i) scanf("%d %d %d", x + i, y + i, s + i);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d %d %d", &query[i].t, &query[i].x1, &query[i].y1,
          &query[i].x2, &query[i].y2);
    query[i].t %= (c + 1);
    query[i].i = i;
  }
  sort(query, query + q);
  int curT = -1;
  for (int i = 0; i < q; ++i) {
    if (query[i].t != curT) {
      doStuff(query[i].t);
      curT = query[i].t;
    }
    for (int x = query[i].x1; x <= query[i].x2; ++x) {
      result[query[i].i] += cum[x][query[i].y2] - cum[x][query[i].y1 - 1];
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
  return 0;
}
