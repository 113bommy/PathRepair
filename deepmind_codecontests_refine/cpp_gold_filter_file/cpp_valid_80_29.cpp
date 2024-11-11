#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, mid, l1, r1, l2, r2;
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", &s);
    mid = n / 2;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (i + 1 <= mid && s[i] == '0') {
        l1 = i + 1;
        r1 = i + mid + 1;
        l2 = i + 2;
        r2 = i + mid + 1;
        flag = 1;
        break;
      }
      if (i + 1 > mid && s[i] == '0') {
        l1 = i - mid + 1;
        r1 = i + 1;
        l2 = i - mid + 1;
        r2 = i;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      printf("%d %d %d %d\n", 1, mid, 2, mid + 1);
    } else {
      printf("%d %d %d %d\n", l1, r1, l2, r2);
    }
  }
  return 0;
}
