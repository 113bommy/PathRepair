#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << (n * 6 - 1) * k << endl;
  for (int i = 1; i <= n; i++) {
    int x = i * 6 - 5;
    cout << x * k << " " << (x + 1) * k << " " << (x + 2) * k << " "
         << (x + 4) * k << endl;
  }
  return 0;
}
