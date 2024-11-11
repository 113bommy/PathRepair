#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
const int N = 1e3 + 50;
const int maxn = 2e5 + 50;
const int maxm = 5e5 + 50;
int n, x, y;
int a[maxn];
int main() {
  int flag = 0, vis = 0, mini[maxn], t = 0;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    for (int j = i; j >= (i - x <= 1 ? 1 : i - x); j--) {
      if (a[j] < a[i]) {
        flag = 0;
        break;
      }
      flag = 1;
    }
    for (int j = i; j <= (i + y >= n ? n : i + y); j++) {
      if (a[j] < a[i]) {
        vis = 0;
        break;
      }
      vis = 1;
    }
    if (vis && flag) {
      mini[t] = i;
      t++;
    }
  }
  printf("%d\n", mini[0]);
  return 0;
}
