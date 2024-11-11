#include <bits/stdc++.h>
using namespace std;
int a[100005][10];
int top[100005] = {0};
int vis[100005] = {0};
void cr(int x, int y) {
  int f1 = 1;
  int i = 1;
  while (i <= top[x]) {
    if (a[x][i] == y) {
      f1 = 0;
      break;
    }
    i++;
  }
  if (f1 == 1) {
    top[x]++;
    a[x][top[x]] = y;
  }
}
int check(int x, int y) {
  int i = 1;
  while (i <= top[x]) {
    if (a[x][i] == y) {
      return 1;
    }
    i++;
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  int i = 1;
  while (i <= n - 2) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    cr(x, y);
    cr(x, z);
    cr(y, x);
    cr(y, z);
    cr(z, x);
    cr(z, y);
    i++;
  }
  i = 1;
  while (i <= n) {
    if (top[i] == 2) {
      break;
    }
    i++;
  }
  int da[100005];
  da[1] = i;
  vis[i] = 1;
  if (top[a[i][1]] == 3) {
    i = a[i][1];
  } else {
    i = a[i][2];
  }
  da[2] = i;
  vis[i] = 1;
  int k = 3;
  while (k <= n) {
    int j = 1;
    while (j <= 4) {
      if (vis[a[i][j]] == 0 && check(a[i][j], da[k - 1]) &&
          check(a[i][j], da[k - 2])) {
        da[k] = a[i][j];
        vis[a[i][j]] = 1;
        i = a[i][j];
        break;
      }
      j++;
    }
    k++;
  }
  i = 1;
  while (i <= n) {
    if (i != 1) cout << " ";
    cout << da[i];
    i++;
  }
  cout << endl;
  return 0;
}
