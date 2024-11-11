#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << 4 + 3 * n << endl;
  cout << 0 << " " << 0 << endl;
  cout << 1 << " " << 0 << endl;
  for (int i = 1; i <= n; i++) {
    cout << i - 1 << " " << i << endl;
    cout << i << " " << i << endl;
    cout << i + 1 << " " << i << endl;
  }
  cout << n << " " << n + 1 << endl;
  cout << n + 1 << " " << n + 1 << endl;
  return 0;
}
