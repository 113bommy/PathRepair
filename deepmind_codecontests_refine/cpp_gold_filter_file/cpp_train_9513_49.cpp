#include <bits/stdc++.h>
using namespace std;
long long pos(long long a) { return a * a + 100000; }
long long neg(long long a) { return -a * a - 100000; }
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n >= 5) {
    puts("-1");
    return 0;
  }
  for (long long int i = 0; i < m; ++i) {
    printf("%I64d %I64d\n", i, pos(i));
  }
  for (long long int i = 0; i < n - m; ++i) {
    printf("%I64d %I64d\n", i, neg(i));
  }
  return 0;
}
