#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int a[q];
  for (int t = 0; t < q; t++) {
    int n;
    cin >> n;
    if (n == 2) {
      a[t] = 2;
      continue;
    }
    a[t] = n % 2;
  }
  for (int i = 0; i < q; i++) cout << a[i] << "\n";
  return 0;
}
