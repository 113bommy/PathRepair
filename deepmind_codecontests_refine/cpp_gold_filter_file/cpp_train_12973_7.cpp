#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 1e9;
  int x;
  scanf("%d", &x);
  int s = sqrt(1000000);
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j <= s; ++j) {
      if (i * j >= x) {
        ans = min(ans, i * 2 + j * 2);
      }
    }
  }
  printf("%d\n", ans);
}
