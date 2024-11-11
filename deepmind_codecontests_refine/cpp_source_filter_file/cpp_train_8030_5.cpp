#include <bits/stdc++.h>
using namespace std;
const int maxn = 300300;
int a[maxn];
set<int> st;
int MIN(int x, int y) { return x < y ? x : y; }
int MAX(int x, int y) { return x > y ? x : y; }
int main(void) {
  st.clear();
  int n, i, j, mi, mx, fg = 0, x;
  scanf("%d", &n);
  for (i = 1; i <= n - 1; i++) {
    scanf("%d", &a[i]);
    if (i == 1) {
      mx = mi = a[i];
    } else {
      a[i] = a[i] + a[i - 1];
      mx = MAX(mx, a[i]);
      mi = MIN(mi, a[i]);
    }
    if (!st.count(x)) {
      st.insert(x);
    } else
      fg = 1;
    if (a[i] == 0) fg = 1;
  }
  if (fg) {
    printf("-1\n");
    return 0;
  }
  for (i = 1; i <= n; i++)
    if (i + mx >= 1 && i + mx <= n && i + mi >= 1 && i + mi <= n) {
      fg = 1;
      x = i;
      break;
    }
  if (fg == 0) {
    printf("-1\n");
  } else {
    printf("%d", x);
    for (i = 1; i <= n - 1; i++) {
      printf(" %d", x + a[i]);
    }
    printf("\n");
  }
  return 0;
}
