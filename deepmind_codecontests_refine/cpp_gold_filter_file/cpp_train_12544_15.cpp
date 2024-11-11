#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int n, a, b, c, ans, ok, S;
struct node {
  int x, y, id;
  bool operator<(const node& A) const {
    if (x / S != A.x / S) return x / S < A.x / S;
    if (x / S & 1) return y < A.y;
    return y > A.y;
  }
} G[M];
int main() {
  scanf("%d", &n);
  S = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &G[i].x, &G[i].y);
    G[i].id = i;
  }
  sort(G + 1, G + n + 1);
  for (int i = 1; i <= n; i++) printf("%d ", G[i].id);
  return 0;
}
