#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x, y;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  bool isok = 0;
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    if (x < 5 || (n - x + 1) < 5) isok = 1;
    if (y < 5 || (m - y + 1) < 5) isok = 1;
  }
  puts(isok ? "YES" : "NO");
  return 0;
}
