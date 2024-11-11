#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    puts("no solution");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << "0 " << i + 1 << endl;
  }
}
