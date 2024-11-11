#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t, x, y;
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%d", &x, &y);
    if (x <= 5 || y <= 5 || n - x <= 4 || m - y <= 4) return puts("YES"), 0;
  }
  puts("NO");
}
