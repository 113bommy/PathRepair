#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  set<int> s;
  int sz = 0;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      if (i >= k) s.insert(i);
      if (m / i >= k && m / i < m) s.insert(m / i);
    }
  }
  sz = s.size();
  if (sz == 0) {
    printf("Marsel\n");
    return 0;
  }
  if (n % 2 == 0)
    printf("Marsel\n");
  else
    printf("Timur\n");
  return 0;
}
