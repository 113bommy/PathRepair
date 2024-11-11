#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
int a[maxn][2];
int vis[maxn];
struct node {
  int pos, val;
};
node mi[maxn], ma[maxn];
bool cmp(node a, node b) { return a.pos > b.pos; }
bool cmp2(node a, node b) { return a.pos < b.pos; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a[i][0] = 0x3f3f3f3f;
  }
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    a[x][0] = min(a[x][0], i);
    a[x][1] = max(a[x][1], i);
    vis[x] = 1;
  }
  int tot = 0;
  node temp;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      temp.val = i;
      temp.pos = a[i][0];
      mi[tot] = temp;
      temp.pos = a[i][1];
      ma[tot++] = temp;
    }
  }
  sort(mi, mi + tot, cmp2);
  sort(ma, ma + tot, cmp);
  if (mi[0].val != ma[0].val) {
    printf("%d\n", ma[0].pos - mi[0].pos);
  } else {
    int ans = 0;
    ans = max(ma[1].pos - mi[0].pos, ma[0].pos - mi[1].pos);
    printf("%d\n", ans);
  }
  return 0;
}
