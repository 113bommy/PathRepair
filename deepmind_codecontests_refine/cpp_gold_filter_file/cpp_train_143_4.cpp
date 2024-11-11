#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
struct node {
  int op;
  int l;
  int r;
  int d;
} cmd[maxn];
;
int a[maxn];
int b[maxn];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> cmd[i].op >> cmd[i].l >> cmd[i].r >> cmd[i].d;
  for (int i = 1; i <= n; i++) a[i] = 100000000;
  for (int i = 1; i <= m; i++) {
    if (cmd[i].op == 1) {
      for (int j = cmd[i].l; j <= cmd[i].r; j++) b[j] += cmd[i].d;
    } else {
      for (int j = cmd[i].l; j <= cmd[i].r; j++) {
        a[j] = min(a[j], cmd[i].d - b[j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 1; i <= m; i++) {
    if (cmd[i].op == 1) {
      for (int j = cmd[i].l; j <= cmd[i].r; j++) b[j] += cmd[i].d;
    } else {
      int flag = INT_MIN;
      for (int j = cmd[i].l; j <= cmd[i].r; j++) flag = max(flag, b[j]);
      if (flag != cmd[i].d) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
