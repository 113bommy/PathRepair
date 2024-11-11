#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, id;
  void in(int k) {
    scanf("%d%d", &a, &b);
    id = k;
  }
  bool operator<(const node &p) const {
    if (a == p.a) return b > p.b;
    return a < p.a;
  }
} tmp;
int ans[101000][2];
int cur[101000];
vector<node> v;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].in(i);
  }
  sort(v.begin(), v.end());
  int now = 1, flag = 1, c1 = 1;
  for (int i = 1; i <= n; i++) cur[i] = i - 1;
  for (int i = 0; i < m; i++) {
    if (v[i].b == 0) {
      if (i - (now - 1) > 1ll * (now - 1) * (now - 2) / 2)
        flag = 0;
      else {
        ans[v[i].id][0] = c1, ans[v[i].id][1] = cur[c1];
        cur[c1]--;
        while (cur[c1] == 1) c1--;
      }
    } else if (v[i].b) {
      now++;
      ans[v[i].id][0] = 1;
      ans[v[i].id][1] = now;
      c1 = now;
    }
  }
  if (flag == 0) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", ans[i][0], ans[i][1]);
  }
}
