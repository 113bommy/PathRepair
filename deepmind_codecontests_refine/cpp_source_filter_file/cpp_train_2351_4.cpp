#include <bits/stdc++.h>
using namespace std;
const int MAX = 1.5e5 + 7;
int n, m;
int pre[MAX], a[MAX], b[MAX], c[MAX] = {0}, d[MAX] = {0}, e[MAX] = {0};
int find(int x) {
  int r = x;
  while (pre[r] != r) r = pre[r];
  int i = x, j;
  while (r != i) {
    j = pre[i];
    pre[i] = r;
    i = j;
  }
  return r;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pre[i] = i;
  for (int i = 1; i <= n; i++) d[i] = 1, e[i] = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x = find(x);
    y = find(y);
    if (x != y) {
      pre[y] = x;
      e[x] += e[y] + 1;
      e[y] = 0;
      d[x] += d[y];
      d[y] = 0;
    } else
      e[x]++;
  }
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    if (d[i] && e[i] != (d[i] - 1) * d[i] / 2) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
