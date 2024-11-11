#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "{";
  for (const T &a : v) out << a << ", ";
  out << "}";
  return out;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int INF = 1000000010;
int osobno(int c, int n) {
  if (c <= n) return INF;
  return 3;
}
int heura2(int c, int n) {
  if (n <= c - 1) {
    return 3;
  }
  int res = INF;
  int kursy = 4;
  n -= c - 1;
  for (;;) {
    if (2 * n <= c) {
      res = min(res, kursy + 1);
      break;
    }
    n -= (c / 2) - 1;
    kursy += 2;
    res = min(res, kursy + osobno(c, n));
  }
  return res;
}
int heura(int c, int n) {
  assert(c > 3);
  int res = heura2(c, n);
  int kursy = 0;
  for (;;) {
    if (2 * n <= c) {
      res = min(res, kursy + 1);
      break;
    }
    n -= (c / 2) - 1;
    kursy += 2;
    res = min(res, kursy + osobno(c, n));
  }
  return res;
}
bool safe(int w, int g) { return w <= g || g == 0; }
int dist[2][1003][1003];
int solve(int c, int n) {
  for (int i = (0); i < (2); ++i)
    for (int j = (0); j < (n + 1); ++j)
      for (int k = (0); k < (n + 1); ++k) dist[i][j][k] = INF;
  dist[0][n][n] = 0;
  queue<tuple<int, int, int> > Q;
  Q.push(tuple<int, int, int>{0, n, n});
  while (!Q.empty()) {
    int s, w, g;
    tie(s, w, g) = Q.front();
    Q.pop();
    int d = dist[s][w][g];
    for (int a = (0); a < (min(w, c) + 1); ++a)
      for (int b = (0); b < (min(g, c - a) + 1); ++b)
        if (a + b && safe(w - a, g - b) && safe(n - w + a, n - g + b) &&
            safe(a, b))
          if (dist[1 - s][n - w + a][n - g + b] == INF) {
            dist[1 - s][n - w + a][n - g + b] = d + 1;
            Q.push(tuple<int, int, int>{1 - s, n - w + a, n - g + b});
          }
  }
  if (dist[1][n][n] == INF) dist[1][n][n] = -1;
  return dist[1][n][n];
}
int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  if (c < 4) {
    if (n < 14)
      printf("%d\n", solve(c, n));
    else
      printf("-1\n");
  } else
    printf("%d\n", heura(c, n));
  return 0;
}
