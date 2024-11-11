#include <bits/stdc++.h>
using namespace std;
int m;
long long power(long long u, long long p) {
  if (p == 0)
    return 1;
  else if (p == 1)
    return u;
  long long x = power(u, p / 2) % m;
  if (p % 2 == 0)
    return (x * x) % m;
  else
    return (x * x * u) % m;
}
int main() {
  int cnt;
  cin >> m;
  cnt = 0;
  bool check;
  for (int i = 1; i < m; i++) {
    check = 1;
    for (int j = 1; j < m - 1; j++) {
      if (!((power(i, j) - 1) % m)) {
        check = 0;
        break;
      }
    }
    if (check && !(power(i, m - 1) - 1)) cnt++;
  }
  printf("%d", cnt);
}
