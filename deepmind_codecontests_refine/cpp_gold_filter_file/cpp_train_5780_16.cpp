#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
vector<node> A, B;
node ans[100005];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  memset(ans, 0, sizeof(ans));
  int n, m, j, k;
  scanf("%d%d", &n, &m);
  A.clear();
  B.clear();
  for (j = 1; j <= m; j++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 1)
      A.push_back((node){a, j});
    else
      B.push_back((node){a, j});
  }
  if (A.size() < n - 1) {
    printf("-1\n");
    return 0;
  }
  sort(A.begin(), A.end(), cmp);
  sort(B.begin(), B.end(), cmp);
  int now = 0;
  for (j = 0; j < A.size(); j++) {
    ans[A[j].y] = (node){j, j + 1};
  }
  int ok;
  for (j = 1; j < A.size(); j++) {
    ok = 1;
    for (k = 1; k <= j; k++) {
      if (now == B.size()) break;
      if (B[now].x < A[j].x) {
        ok = 0;
        break;
      }
      ans[B[now].y] = (node){j - k, j + 1};
      now++;
    }
    if (!ok) break;
    if (now == B.size()) break;
  }
  if (!ok)
    printf("-1\n");
  else {
    for (j = 1; j <= m; j++) {
      printf("%d %d\n", ans[j].x + 1, ans[j].y + 1);
    }
  }
  return 0;
}
