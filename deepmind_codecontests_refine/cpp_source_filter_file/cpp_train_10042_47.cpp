#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f = 0;
  cin >> n;
  for (int i = 1; i < 29; i++) {
    if ((i * (i + 1)) / 2 == n) {
      f = 1;
      break;
    }
    if (i > n) break;
  }
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
