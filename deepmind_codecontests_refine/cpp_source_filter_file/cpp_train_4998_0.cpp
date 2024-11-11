#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, i = 1;
  scanf("%d", &n);
  while (true) {
    if (i * 2 > n) {
      printf("%d\n", ans);
      return 0;
    } else {
      ans++;
    }
    i *= 2;
  }
}
