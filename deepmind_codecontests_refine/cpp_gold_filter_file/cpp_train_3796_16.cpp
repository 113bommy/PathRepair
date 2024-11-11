#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << (6 * n - 1) * k << endl;
  int x = 1;
  for (int i = 1; i <= n; i++) {
    cout << (x + 1) * k << " ";
    cout << x * k << " ";
    x += 2;
    cout << x * k << " ";
    x += 2;
    cout << x * k << " ";
    x += 2;
    cout << endl;
  }
  return 0;
}
