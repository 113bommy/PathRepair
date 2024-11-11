#include <bits/stdc++.h>
using namespace std;
int m, n;
int abss(int a) { return a < 0 ? -a : a; }
struct node {
  int x, y;
};
vector<node> a[4][11];
bool cmp1(const node &a, const node &b) {
  return abss(a.x - 1) + abss(a.y - 1) < abss(b.x - 1) + abss(b.y - 1);
}
bool cmp2(const node &a, const node &b) {
  return abss(a.x - 1) + abss(a.y - m) < abss(b.x - 1) + abss(b.y - m);
}
bool cmp3(const node &a, const node &b) {
  return abss(a.x - n) + abss(a.y - 1) < abss(b.x - n) + abss(b.y - 1);
}
bool cmp4(const node &a, const node &b) {
  return abss(a.x - n) + abss(a.y - m) < abss(b.x - n) + abss(b.y - m);
}
int dis(node a, node b) { return abss(a.x - b.x) + abss(a.y - b.y); }
int cc[120000];
int main() {
  int t;
  node tmp;
  int s, k;
  scanf("%d %d %d %d", &n, &m, &s, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &t);
      tmp.x = i;
      tmp.y = j;
      for (int x = 0; x < 4; x++) a[x][t].push_back(tmp);
    }
  for (int i = 1; i <= s; i++) {
    sort(a[0][i].begin(), a[0][i].end(), cmp1);
    sort(a[1][i].begin(), a[1][i].end(), cmp2);
    sort(a[2][i].begin(), a[2][i].end(), cmp3);
    sort(a[3][i].begin(), a[3][i].end(), cmp4);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &cc[i]);
  }
  int ans = 0;
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      node ac = a[j][cc[i - 1]][0];
      node wa = a[j][cc[i]][a[j][cc[i]].size() - 1];
      ans = max(ans, dis(ac, wa));
    }
  }
  cout << ans << endl;
}
