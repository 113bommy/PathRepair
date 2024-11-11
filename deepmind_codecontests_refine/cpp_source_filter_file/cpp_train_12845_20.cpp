#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m > n * (n - 1) / 2) {
    puts("no solution");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    printf("0 %d\n", i);
  }
}
