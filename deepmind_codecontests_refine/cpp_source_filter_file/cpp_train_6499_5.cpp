#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main() {
  int n, q;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) ans ^= a[i][j] ^ a[j][i];
  scanf("%d", &q);
  for (int t; q--;) {
    scanf("%d", &t);
    switch (t) {
      case 1:
      case 2:
        scanf("%*d");
        ans ^= n;
        break;
      case 3:
        putchar('0' + (ans & 1));
    }
  }
}
