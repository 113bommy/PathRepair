#include <bits/stdc++.h>
using namespace std;
inline int rd(int& ret) {
  ret = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  ret *= f;
}
int c[300005];
char s[300005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    scanf("%s", s + 1);
    for (register int i = 0; i < k; i++) c[i] = -1;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0') {
        if (c[i % k] == 1) {
          flag = 0;
          break;
        }
        c[i % k] = 0;
      }
      if (s[i] == '1') {
        if (c[i % k] == 0) {
          flag = 0;
          break;
        }
        c[i % k] = 1;
      }
    }
    if (!flag) {
      printf("NO\n");
      continue;
    }
    int cnt = 0, num = 0;
    for (int i = 0; i < k; i++) {
      if (~c[i]) {
        num += c[i];
      } else {
        cnt++;
      }
    }
    if (num > (k >> 1)) {
      printf("NO\n");
      continue;
    }
    if (num + cnt >= (k >> 1)) {
      printf("YES\n");
      continue;
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
