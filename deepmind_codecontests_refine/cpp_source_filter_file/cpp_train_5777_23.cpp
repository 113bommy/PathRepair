#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2 || n == 1) {
    cout << 1 << endl;
    cout << 1;
    return 0;
  }
  if (n == 3) {
    cout << 2;
    cout << "1 3";
    return 0;
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) cout << i << " ";
  }
  for (int i = 1; i <= n; i++)
    if (i % 2) cout << i << " ";
  return 0;
}
