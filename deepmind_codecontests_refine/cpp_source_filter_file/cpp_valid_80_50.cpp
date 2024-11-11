#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
char str[N];
int n;
bool judge(int l1, int r1, int l2, int r2) {
  return r1 - l1 + 1 >= n / 2 && r2 - l2 + 1 >= n / 2;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %s", &n, str + 1);
    int pos = 0;
    for (int i = 1; i <= n; i++) {
      if (str[i] == '0') {
        pos = i;
        break;
      }
    }
    if (pos) {
      if (judge(pos, n, pos + 1, n)) {
        printf("%d %d %d %d\n", pos, n, pos + 1, n);
      } else {
        printf("%d %d %d %d\n", 1, pos, 1, pos - 1);
      }
    } else {
      printf("%d %d %d %d\n", 1, n / 2, n, n - n / 2 + 1);
    }
  }
  return 0;
}
