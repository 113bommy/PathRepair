#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
int n, k, a[5][MAXN], s;
struct Node {
  int id, x, y;
  Node(int id, int x, int y) : id(id), x(x), y(y) {}
};
vector<Node> ans;
void park() {
  for (int i = 0; i < 2 * n; i++)
    if (a[1][i] && a[1][i] == a[0][i]) {
      ans.push_back(Node(a[1][i], i / n ? 4 : 1, i % n + 1));
      a[1][i] = 0;
      k--;
    }
}
bool judge() {
  park();
  for (int i = 0; i < 2 * n; i++)
    if (!a[1][i]) return true;
  return false;
}
void turn() {
  vector<Node> v1, v2;
  int t = a[1][2 * n - 1];
  for (int i = 2 * n - 1; i >= 1; i--) {
    a[1][i] = a[1][i - 1];
    if (a[1][i]) {
      if (i <= s)
        v1.push_back(Node(a[1][i], i / n ? 3 : 2, i % n + 1));
      else
        v2.push_back(Node(a[1][i], i / n ? 3 : 2, i % n + 1));
    }
  }
  a[1][0] = t;
  if (t) v2.push_back(Node(t, 2, 1));
  for (auto i : v1) ans.push_back(i);
  for (auto i : v2) ans.push_back(i);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
  for (int i = 2 * n - 1; i >= n; i--) scanf("%d", &a[1][i]);
  for (int i = 2 * n - 1; i >= n; i--) scanf("%d", &a[0][i]);
  if (!judge()) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < 2 * n; i++)
    if (!a[1][i]) {
      s = i;
      break;
    }
  while (k) {
    turn();
    park();
    s = (s + 1) % (2 * n);
  }
  printf("%d\n", ans.size());
  for (auto i : ans) {
    if (i.x == 3 || i.x == 4) i.y = n - i.y + 1;
    printf("%d %d %d\n", i.id, i.x, i.y);
  }
  return 0;
}
