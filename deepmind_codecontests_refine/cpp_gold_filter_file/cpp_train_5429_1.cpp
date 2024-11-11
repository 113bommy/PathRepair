#include <bits/stdc++.h>
using namespace std;
const int N = 305;
struct Node {
  int x, y;
} p[N];
long long dp[N][N][6];
inline long long cross(Node a, Node b) {
  return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
Node operator-(Node a, Node b) { return (Node){a.x - b.x, a.y - b.y}; }
Node operator+(Node a, Node b) { return (Node){a.x + b.x, a.y + b.y}; }
bool operator<(Node a, Node b) { return cross(a, b) < 0; }
struct Line {
  Node v;
  int a, b;
};
vector<Line> E;
bool operator<(Line a, Line b) {
  if (a.v < b.v) return true;
  if (b.v < a.v) return false;
  if (a.a != b.a) return a.a < b.a;
  return a.b < b.b;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) E.push_back((Line){p[j] - p[i], i, j});
  sort(E.begin(), E.end());
  for (int t = 0; t < E.size(); t++) {
    int u = E[t].a, v = E[t].b;
    dp[u][v][0]++;
    for (int i = 0; i < 5; i++)
      for (int j = 1; j <= n; j++) dp[j][v][i + 1] += dp[j][u][i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[i][i][4];
  printf("%lld", ans);
  return 0;
}
