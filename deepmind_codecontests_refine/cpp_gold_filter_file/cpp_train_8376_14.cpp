#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int b[maxn];
int sum[maxn];
char a[maxn][maxn];
int n;
int ti(char a[], int sum, int key) {
  if (sum >= 0 && sum <= 9 * key) {
    for (int i = 0; i < key; i++) {
      if (sum >= 9) {
        a[i] = '9';
        sum -= 9;
      } else {
        a[i] = sum + '0';
        sum = 0;
      }
    }
    return 1;
  } else {
    return 0;
  }
}
void getOk(char a[], char b[], int key) {
  int n = strlen(a);
  sum[0] = a[0] - '0';
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i] - '0';
  }
  for (int i = 0; i < n; i++) {
    int t = key;
    t -= (sum[n - 1] - sum[i]);
    for (int j = a[i] - '0' + 1; j <= 9; j++) {
      if (ti(b, t - j, i)) {
        b[i] = j + '0';
        for (int k = i + 1; k < n; k++) {
          b[k] = a[k];
        }
        return;
      }
    }
  }
  int tmp = n + 1;
  while (tmp * 9 < key) {
    tmp++;
  }
  for (int i = 1; i <= 9; i++) {
    if (ti(b, key - i, tmp - 1)) {
      b[tmp - 1] = i + '0';
      return;
    }
  }
}
void solve() {
  memset(a, 0, sizeof(a));
  a[0][0] = '0';
  for (int i = 1; i <= n; i++) {
    getOk(a[i - 1], a[i], b[i]);
  }
  for (int i = 1; i <= n; i++) {
    int t = strlen(a[i]);
    for (int j = t - 1; j >= 0; j--) {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    solve();
  }
  return 0;
}
