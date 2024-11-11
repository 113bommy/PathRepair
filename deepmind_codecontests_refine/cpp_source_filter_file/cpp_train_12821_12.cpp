#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int r[MAXN], c[MAXN], r1[MAXN], c1[MAXN], n;
struct Node {
  int x1, y1, x2, y2;
};
vector<Node> ans;
void push(int x1, int y1, int x2, int y2) {
  ans.push_back((Node){x1, y1, x2, y2});
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", r + i);
    r1[r[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
    c1[c[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] == i && c[i] == i) continue;
    push(i, c[i], r[i], i);
    if (r1[i] > i) r[r1[i]] = r[i], r1[r[i]] = r1[i];
    if (c1[i] > i) c[c1[i]] = c[i], c1[c[i]] = c1[i];
  }
  printf("%d\n", (int)ans.size());
  for (Node d : ans) printf("%d %d %d %d\n", d.x1, d.y1, d.x2, d.y2);
  return 0;
}
