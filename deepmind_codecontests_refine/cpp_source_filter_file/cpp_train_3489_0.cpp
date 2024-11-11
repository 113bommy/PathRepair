#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
struct Node {
  long long x, y;
  int id;
  Node(long long x = 0, long long y = 0, int id = 0) : x(x), y(y), id(id) {}
  bool operator<(const Node& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};
int n;
Node V[maxn];
bool cmp(int a, int b) { return V[a].y < V[b].y; }
bool judge(int a, int b, int c) {
  long long p1x = V[b].x - V[a].x;
  long long p1y = V[b].y - V[a].y;
  long long p2x = V[c].x - V[a].x;
  long long p2y = V[c].y - V[a].y;
  return p1x * p2y == p1y * p2x;
}
int main() {
  scanf("%d", &n);
  int curx = 0, cury = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    V[i] = Node(x, y, i);
  }
  sort(V, V + n);
  int a = V[0].id;
  int b = V[1].id;
  int p = 2;
  while (judge(a, b, V[p].id)) p++;
  int c = V[p].id;
  printf("%d %d %d\n", a + 1, b + 1, c + 1);
  return 0;
}
