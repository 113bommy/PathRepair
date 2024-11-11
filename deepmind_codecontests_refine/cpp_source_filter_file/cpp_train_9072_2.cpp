#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int x;
int main() {
  cin >> x;
  int ans = x / 2 + 1;
  printf("%d\n", ans);
  for (int i = 1; i <= x && i <= ans; i++) {
    printf("%d %d\n", 1, i);
  }
  for (int i = ans + 1; i <= x; i++) {
    printf("%d %d\n", ans, ans - (i - ans - 1));
  }
}
