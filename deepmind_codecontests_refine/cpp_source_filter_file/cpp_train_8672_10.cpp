#include <bits/stdc++.h>
using namespace std;
const int INF = 1000005;
const long long INFLL = 1000000000000000005ll;
const long long MOD = 1000000007;
const int RIGHT = 262144;
const int SIZE = 525000;
struct Node {
  double left, right, total, sum;
  Node(double p1 = 0, double p2 = 0, double p3 = 0, double p4 = 0)
      : left(p1), right(p2), total(p3), sum(p4){};
};
Node merge(Node n1, Node n2) {
  double l = max(n1.left, n1.sum + n2.left);
  double r = max(n2.right, n2.sum + n1.right);
  double s = n1.sum + n2.sum;
  double t = max(max(n1.total, n2.total), n1.right + n2.left);
  return {l, r, t, s};
}
double C, P[150005], X[150005];
int N, M;
Node Tree[SIZE];
Node query(int l, int r, int n, int a, int b) {
  if (a > r || b < l) return {0, 0, 0, 0};
  if (a >= l && b <= r) return Tree[n];
  int mid = (a + b) / 2;
  Node nl = query(l, r, 2 * n, a, mid);
  Node nr = query(l, r, 2 * n + 1, mid + 1, b);
  return merge(nl, nr);
}
void update(int x, double v, int n, int a, int b) {
  if (a > x || b < x) return;
  if (a == b) {
    Tree[n] = {v, v, v, v};
    return;
  }
  int mid = (a + b) / 2;
  update(x, v, 2 * n, a, mid);
  update(x, v, 2 * n + 1, mid + 1, b);
  Tree[n] = merge(Tree[2 * n], Tree[2 * n + 1]);
}
int main() {
  cin >> N >> M >> C;
  for (long long i = (1); i <= (N); i++) cin >> X[i];
  for (long long i = (1); i <= (N - 1); i++) cin >> P[i];
  for (long long i = (1); i <= (N - 1); i++)
    update(i, (X[i + 1] - X[i]) / 2 - P[i] / 100.0 * C, 1, 1, RIGHT);
  double ans = 0;
  for (long long i = (1); i <= (M); i++) {
    int a, b;
    cin >> a >> b;
    b--;
    Node n = query(a, b, 1, 1, RIGHT);
    double x = max(max(max(n.left, n.right), n.sum), n.right);
    ans += x;
  }
  cout << fixed << setprecision(15) << ans;
}
