#include <bits/stdc++.h>
using namespace std;
long long input() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
const int N = 1e3 + 7;
int n;
int a[N];
int main() {
  int T = input();
  while (T--) {
    n = input();
    for (int i = 1; i <= n; i++) {
      a[i] = input();
    }
    sort(a + 1, a + 1 + n);
    int len = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] >= len + 1)
        len++;
      else
        break;
    }
    printf("%d\n", len);
  }
}
