#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int x = -1;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0') x = i;
    }
    if (x >= (n / 2) + 1)
      printf("1 %d 1 %d\n", x, x - 1);
    else if (x >= 1)
      printf("%d %d %d %d", x, n, x + 1, n);
    else
      printf("1 %d 2 %d\n", n - 1, n);
  }
}
