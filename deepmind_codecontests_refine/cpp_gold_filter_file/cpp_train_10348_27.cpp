#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a = m > n ? m : n;
  cout << (m + n - 1) << endl;
  for (int i = 1; i <= a; ++i) {
    if (a == m)
      cout << "1 " << i << endl;
    else
      cout << i << " 1" << endl;
  }
  for (int i = 2; i <= m + n - a; ++i) {
    if (a == m)
      cout << i << " 1" << endl;
    else
      cout << "1 " << i << endl;
  }
  return 0;
}
