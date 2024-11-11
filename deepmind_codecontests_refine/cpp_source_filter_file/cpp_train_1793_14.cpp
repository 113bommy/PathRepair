#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int a[MAXN][1 << 3];
int f[MAXN];
int id1, id2;
int n, m;
bool check(int ans) {
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }
  int mx = (1 << m) - 1, temp;
  for (int i = 1; i <= n; i++) {
    temp = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= ans) temp |= 1 << j;
    }
    for (int x = temp; x; x = (x - 1) & temp) {
      if (f[x]) break;
      f[x] = i;
    }
    f[0] = i;
    temp ^= mx;
    if (f[temp]) {
      id1 = i, id2 = f[temp];
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int L = 0, R = 1 << 30, mid;
  while (L <= R) {
    mid = L + R >> 1;
    if (check(mid)) {
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  printf("%d %d", id1, id2);
  return 0;
}
