#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cout << i << " " << n * n - (i - 1) << "\n";
  }
  return 0;
}
