#include <bits/stdc++.h>
using namespace std;
int n, m;
bool pd() {
  if (n <= 3) return 1;
  while (m) {
    int x = m % n;
    if (x <= 1)
      m /= n;
    else if (x == n - 1)
      (m /= n) += 1;
    else
      return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  printf(pd() ? "YES\n" : "NO\n");
  return 0;
}
