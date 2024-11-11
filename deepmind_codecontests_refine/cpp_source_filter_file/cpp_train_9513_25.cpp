#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && m > 4) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= m; ++i) printf("%d %d\n", i * i + 100000, i);
  for (int i = 1; i <= n - m; ++i) printf("%d %d\n", -i * i, i);
  return 0;
}
