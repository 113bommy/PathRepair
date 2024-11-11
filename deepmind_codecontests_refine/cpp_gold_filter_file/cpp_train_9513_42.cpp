#include <bits/stdc++.h>
using namespace std;
const int h = 10000000;
int main() {
  ios ::sync_with_stdio(0);
  int i, j, n, m;
  cin >> n >> m;
  if (n >= 5 && m == 3)
    puts("-1");
  else {
    for (i = 1; i <= m; i++) printf("%d %d\n", i, h + i * i);
    for (i = 1; i <= n - m; i++) printf("%d %d\n", i, -h - i * i);
  }
  return 0;
}
