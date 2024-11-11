#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, mi;
  cin >> n >> m;
  mi = min(n, m);
  cout << mi << "\n";
  for (int i = 0; i <= mi; i++) {
    cout << i << " " << mi - i << "\n";
  }
  return 0;
}
