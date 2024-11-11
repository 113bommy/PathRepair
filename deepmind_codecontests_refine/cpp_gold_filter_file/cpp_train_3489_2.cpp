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
Node operator-(Node A, Node B) { return Node(A.x - B.x, A.y - B.y); }
long long operator*(Node A, Node B) { return A.x * B.y - A.y * B.x; }
long long operator^(Node A, Node B) { return A.x * B.x + A.y * B.y; }
int n;
Node V[maxn];
bool cmp(Node a, Node b) {
  Node A = a - V[0];
  Node B = b - V[0];
  if (A * B == 0)
    return (A ^ A) < (B ^ B);
  else
    return A * B > 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%lld %lld", &x, &y);
    V[i] = Node(x, y, i);
  }
  sort(V, V + n);
  sort(V + 1, V + n, cmp);
  int a = V[0].id;
  int b = V[1].id;
  int p = 2;
  while (p < n && (V[1] - V[0]) * (V[p] - V[1]) == 0) p++;
  int c = V[p].id;
  printf("%d %d %d\n", a + 1, b + 1, c + 1);
  return 0;
}
