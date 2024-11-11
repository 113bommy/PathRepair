#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const long long inf = 1e18;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int N = 1e6;
int n, k, num[300005], nn = 0, num2[300005];
struct node {
  int pos, v;
  node(int _pos = 0, int _v = 0) {
    pos = _pos;
    v = _v;
  }
};
struct cmp {
  bool operator()(const node& a, const node& b) { return a.v > b.v; }
};
struct cmp2 {
  bool operator()(const node& a, const node& b) { return a.pos < b.pos; }
};
priority_queue<node, vector<node>, cmp> q;
priority_queue<node, vector<node>, cmp2> q2;
void gao() {
  sort(num + 1, num + 1 + n);
  int tt = (n + 1) / 2;
  if (k >= tt) {
    printf("%d\n", num[n] - num[1]);
    return;
  }
  int ans = 0;
  num2[1] = 0;
  for (int i = 2; i < k; i++) num2[i] = (1e9 + 7);
  for (int i = k; i <= n; i++) {
    if (num2[i - k + 1] != (1e9 + 7)) q.push(node(i - k + 1, num2[i - k + 1]));
    int res = (1e9 + 7);
    while (!q.empty()) {
      node u = q.top();
      if (num[i] - num[u.pos] >= u.v) {
        q2.push(node(u.pos, 0));
        q.pop();
      } else {
        res = u.v;
        break;
      }
    }
    if (!q2.empty()) {
      node u = q2.top();
      if (res > num[i] - num[u.pos]) res = num[i] - num[u.pos];
    }
    num2[i + 1] = res;
    if (i == n) printf("%d\n", res);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  if (k == 1) {
    puts("0");
    return 0;
  }
  gao();
  return 0;
}
