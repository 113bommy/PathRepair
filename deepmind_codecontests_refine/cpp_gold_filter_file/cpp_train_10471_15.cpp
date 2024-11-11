#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N];
int find1(int x) {
  if (x != a[x]) {
    return a[x] = find1(a[x]);
  }
  return a[x];
}
void join(int x, int y) {
  int x1 = find1(x);
  int y1 = find1(y);
  if (x1 != y1) {
    a[y1] = x1;
  }
}
vector<int> e[N >> 1];
int main() {
  int n, m, x, opt;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m * 2; i++) a[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &opt);
    for (int j = 1; j <= opt; j++) {
      scanf("%d", &x);
      e[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) {
      join(e[i][0], e[i][1]);
      join(e[i][0] + m, e[i][1] + m);
    } else {
      join(e[i][0] + m, e[i][1]);
      join(e[i][0], e[i][1] + m);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (find1(i) == find1(i + m)) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
