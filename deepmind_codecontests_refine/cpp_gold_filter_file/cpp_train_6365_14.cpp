#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k;
long long a[MAXN], b[MAXN];
struct Node {
  long long v, b, s;
  Node() {}
  Node(long long v, long long b, long long s) : v(v), b(b), s(s) {}
  bool operator<(const Node& that) const { return s > that.s; }
};
bool check(long long x) {
  priority_queue<Node> Q;
  for (int i = 0; i < n; i++) Q.push(Node(a[i], b[i], a[i] / b[i]));
  for (int i = 1; i <= k; i++) {
    Node u = Q.top();
    Q.pop();
    if (u.v < u.b * (i - 1)) return false;
    if (u.v / u.b >= k) return true;
    Q.push(Node(u.v + x, u.b, (u.v + x) / u.b));
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  long long L = 0, R = *max_element(b, b + n) * k + 1;
  while (L < R) {
    long long m = L + (R - L) / 2;
    if (check(m))
      R = m;
    else
      L = m + 1;
  }
  if (check(L))
    printf("%lld", L);
  else
    printf("-1");
  return 0;
}
