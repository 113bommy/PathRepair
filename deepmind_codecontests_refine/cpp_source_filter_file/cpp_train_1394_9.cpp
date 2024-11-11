#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <class T>
int chmin(T &t, T f) {
  return (t > f) ? (t = f, 1) : 0;
}
template <class T>
int chmax(T &t, T f) {
  return (t < f) ? (t = f, 1) : 0;
}
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
const int N = 1 << 6;
long long ways[2][N][N], seen[2][N][N], depth[N][N], nck[N][N];
void myCode() {
  for (int i = (int)0; i < (int)1 << 6; i++) nck[i][i] = nck[i][0] = 1;
  for (int i = (int)2; i < (int)1 << 6; i++)
    for (int j = (int)1; j < (int)i; j++)
      nck[i][j] = (nck[i - 1][j] + nck[i - 1][j - 1]) % INF;
  int n = getint(), W = getint() / 50;
  int na = 0, nb = 0;
  for (int i = (int)0; i < (int)n; i++)
    if (getint() == 50)
      ++na;
    else
      ++nb;
  int nextDepth = 1;
  vector<pair<int, int> > q1, q2;
  q1.push_back(pair<int, int>(0, 0));
  ways[0][0][0] = 1;
  while (!q1.empty()) {
    while (!q1.empty()) {
      int i = q1.back().first, j = q1.back().second;
      q1.pop_back();
      if (seen[0][i][j]) continue;
      seen[0][i][j] = 1;
      for (int la = (int)0; la < (int)na - i + 1; la++)
        for (int lb = (int)0; lb < (int)nb - j + 1; lb++)
          if (la + lb && la + 2 * lb <= W && !seen[1][i + la][j + lb]) {
            ways[1][i + la][j + lb] =
                (ways[0][i][j] * (nck[na - i][la] * nck[nb - j][lb] % INF) %
                     INF +
                 ways[1][i + la][j + lb]) %
                INF;
            q2.push_back(pair<int, int>(i + la, j + lb));
          }
    }
    while (!q2.empty()) {
      int i = q2.back().first, j = q2.back().second;
      q2.pop_back();
      if (seen[1][i][j]) continue;
      seen[1][i][j] = 1;
      depth[i][j] = nextDepth;
      for (int la = (int)0; la < (int)i + 1; la++)
        for (int lb = (int)0; lb < (int)j + 1; lb++)
          if (la + lb && la + 2 * lb <= W && !seen[0][i - la][j - lb]) {
            ways[0][i - la][j - lb] =
                (ways[1][i][j] * (nck[i][la] * nck[j][lb] % INF) % INF +
                 ways[0][i - la][j - lb]) %
                INF;
            q1.push_back(pair<int, int>(i - la, j - lb));
          }
    }
    ++nextDepth;
  }
  if (!seen[1][na][nb])
    printf("-1\n0\n");
  else
    printf("%d\n%d\n", 2 * depth[na][nb] - 1, ways[1][na][nb]);
}
int main() {
  myCode();
  return 0;
}
