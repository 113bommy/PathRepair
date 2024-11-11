#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b = 0;
  string m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m == "++x" || m == "x++") {
      b++;
    } else
      b--;
  }
  cout << b << endl;
  return 0;
}
