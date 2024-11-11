#include <bits/stdc++.h>
using namespace std;
int n, k, ans, ly[105], lx[105], slack[105], fy[105], w[105][105], Ans[105];
bool mx[105], my[105];
char a[2000015], b[2000015];
int find(int x) {
  mx[x] = true;
  for (int i = 1; i <= n; i++)
    if (!my[i]) {
      int a = lx[x] + ly[i] - w[x][i];
      if (a == 0) {
        my[i] = true;
        if (!fy[i] || find(fy[i])) {
          fy[i] = x;
          return true;
        }
      } else
        slack[i] = min(slack[i], a);
    }
  return false;
}
void km() {
  memset(lx, 0, sizeof(lx));
  memset(ly, 0, sizeof(ly));
  memset(fy, 0, sizeof(fy));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) lx[i] = max(lx[i], w[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) slack[j] = 2147483647;
    while (true) {
      memset(mx, 0, sizeof(mx));
      memset(my, 0, sizeof(my));
      if (find(i)) break;
      int a = 2147483647;
      for (int j = 1; j <= n; j++)
        if (!my[j]) a = min(a, slack[j]);
      for (int j = 1; j <= n; j++)
        if (mx[j]) lx[j] -= a;
      for (int j = 1; j <= n; j++)
        if (my[j]) {
          ly[j] += a;
        } else
          slack[j] -= a;
    }
  }
}
int got(char x) {
  if (x >= 'a' && x <= 'z')
    return x - 'a' + 1;
  else
    return 27 + x - 'A';
}
char regot(int x) {
  if (x <= 26) return 'a' + x - 1;
  return 'A' + x - 27;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", a);
  scanf("%s", b);
  for (int i = 0; i < n; i++) w[got(a[i])][got(b[i])]++;
  n = k;
  km();
  for (int i = 1; i <= n; i++) ans += lx[i] + ly[i];
  cout << ans << endl;
  for (int i = 1; i <= n; i++) Ans[fy[i]] = i;
  for (int i = 1; i <= n; i++) cout << regot(Ans[i]);
}
