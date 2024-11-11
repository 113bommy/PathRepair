#include <bits/stdc++.h>
using namespace std;
char c[1003];
char s[1003];
int sign[1003];
int fi[1003];
int main() {
  int n, m;
  cin >> n >> m;
  getchar();
  int num = 0;
  int ans = 1001;
  for (int i = 0; i < n; i++) {
    scanf("%c", &c[i]);
  }
  getchar();
  for (int i = 0; i < m; i++) {
    scanf("%c", &s[i]);
  }
  for (int j = 0; j < m - n + 1; j++) {
    memset(sign, 0, sizeof(sign));
    num = 0;
    for (int q = 0; q < n; q++) {
      if (s[j + q] != c[q]) {
        sign[num++] = q + 1;
      }
    }
    if (ans > num) {
      ans = num;
      memcpy(fi, sign, sizeof(int) * num);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < ans; i++) {
    printf("%d ", fi[i]);
  }
  cin >> n;
  return 0;
}
