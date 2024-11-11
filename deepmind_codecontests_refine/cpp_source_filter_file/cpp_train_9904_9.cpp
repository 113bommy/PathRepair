#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int l[301], r[301];
vector<int> s[N], e[N];
int a[N];
int zz[301];
void change(int l, int r, int coun) {
  for (int i = l; i <= r; i++) a[i] += coun;
}
int main() {
  int n;
  int m;
  int id;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &l[i], &r[i]);
    s[l[i]].push_back(i);
    e[r[i] + 1].push_back(i);
  }
  int ans;
  int dd;
  int ma;
  int mi;
  ma = a[1];
  mi = a[1];
  for (int i = 2; i <= n; i++) ma = max(ma, a[i]), mi = min(a[1], mi);
  ans = ma - mi;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      int index = e[i][j];
      change(l[index], r[index], 1);
    }
    for (int j = 0; j < s[i].size(); j++) {
      int index = s[i][j];
      change(l[index], r[index], -1);
    }
    if (!s[i].empty() or !e[i].empty()) {
      ma = a[1];
      mi = a[1];
      for (int k = 2; k <= n; k++) {
        ma = max(ma, a[k]);
        mi = min(mi, a[k]);
      }
      if (ans < ma - mi) ans = ma - mi, dd = i;
    }
  }
  printf("%d\n", ans);
  int head = 0;
  for (int i = 1; i <= m; i++) {
    if (dd >= l[i] && dd <= r[i]) zz[head++] = i;
  }
  printf("%d\n", head);
  for (int i = 0; i < head; i++) printf("%d ", zz[i]);
  return 0;
}
