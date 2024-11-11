#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, m;
  cin >> a >> m;
  int x = a;
  for (int i = 0; i < 100000; ++i) {
    if (x % m == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    x = x + x % m;
  }
  cout << "No" << endl;
  return 0;
}
