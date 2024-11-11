#include <bits/stdc++.h>
using namespace std;
int q[110], a[110];
int p1[110][110];
int p2[110][110];
int main() {
  int n, k, v1, v2;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    p1[0][i] = p2[0][i] = i;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      p1[i][q[j]] = p1[i - 1][j];
      p2[i][j] = p2[i - 1][q[j]];
    }
  }
  bool fff;
  v1 = v2 = -1;
  for (int i = 0; i <= k; i++) {
    fff = true;
    for (int j = 1; j <= n && fff; j++) {
      if (p1[i][j] != a[j]) {
        fff = false;
      }
    }
    if (fff && v1 == -1) {
      v1 = i;
    }
    fff = true;
    for (int j = 1; j <= n && fff; j++) {
      if (p2[i][j] != a[j]) {
        fff = false;
      }
    }
    if (fff && v2 == -1) {
      v2 = i;
    }
  }
  bool flag = false;
  if (v1 >= k || v2 >= k) {
    if (v1 == k || v2 == k) {
      flag = true;
    }
    if ((v1 > k) && (v1 - k) % 2 == 0) {
      flag = true;
    }
    if ((v2 > k) && (v2 - k) % 2 == 0) {
      flag = true;
    }
  } else if (v1 <= k || v2 <= k) {
    if ((v1 != 0) && (k > v1) && (k - v1) % 2 == 0) {
      flag = true;
    }
    if ((v2 != 0) && (k > v2) && (k - v2) % 2 == 0) {
      flag = true;
    }
  }
  if (v1 == 0 && v2 == 0 || v1 == -1 && v2 == -1) {
    flag = false;
  } else if (v1 == 1 && v2 == 1 && k > 1) {
    flag = false;
  }
  printf("%s\n", flag ? "YES" : "NO");
  return 0;
}
