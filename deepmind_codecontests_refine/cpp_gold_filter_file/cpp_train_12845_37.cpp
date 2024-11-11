#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m >= n * (n - 1) / 2) {
    printf("no solution");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", 0, i);
  }
  return 0;
}
