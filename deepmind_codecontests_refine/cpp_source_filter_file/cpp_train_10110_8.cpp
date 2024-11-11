#include <bits/stdc++.h>
using namespace std;
struct node {
  string name;
  int p;
};
node mm[50];
int cmp(node aa, node bb) {
  if (aa.name == bb.name) return aa.p > bb.p;
  return aa.name < bb.name;
}
bool flag[50];
int main() {
  int n, m;
  double k;
  scanf("%d%d%lf", &n, &m, &k);
  int cnt;
  cnt = 0;
  k += 0.000005;
  for (int i = 0; i < n; i++) {
    cin >> mm[cnt].name;
    cin >> mm[cnt].p;
    mm[cnt].p = mm[cnt].p * k;
    if (mm[cnt].p >= 100) cnt++;
  }
  for (int i = 0; i < m; i++) {
    cin >> mm[cnt].name;
    mm[cnt].p = 0;
    cnt++;
  }
  sort(mm, mm + cnt, cmp);
  int ans;
  ans = 1;
  memset(flag, 0, sizeof(flag));
  for (int i = 1; i < cnt; i++) {
    if (mm[i].name == mm[i - 1].name) {
      flag[i] = 1;
    } else
      ans++;
  }
  printf("%d\n", ans);
  for (int i = 0; i < cnt; i++) {
    if (flag[i]) continue;
    cout << mm[i].name << " " << mm[i].p << endl;
  }
}
