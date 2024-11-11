#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n - 1)) <= k) {
    puts("no solution");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << "0 " << i << "\n";
  }
  return 0;
}
