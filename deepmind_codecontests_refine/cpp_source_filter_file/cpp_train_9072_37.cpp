#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  for (int i = 1; i < 40; i++) {
    if (n - 1 <= (i - 1) * 2) {
      m = i;
      break;
    }
  }
  cout << m << endl;
  for (int i = 1; i <= m; i++) {
    cout << "1 " << i << endl;
  }
  int z = n - m;
  for (int i = 1; i <= n - m; i++) {
    cout << m << " " << m - z + 1 << endl;
    z--;
  }
  return 0;
}
