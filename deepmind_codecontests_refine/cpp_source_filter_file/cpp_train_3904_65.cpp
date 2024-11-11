#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x <= 5 || y <= 5 || x + 5 >= n || y + 5 >= m) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
