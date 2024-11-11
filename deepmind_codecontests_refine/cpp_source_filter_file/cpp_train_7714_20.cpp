#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  for (int i = 0; i <= (r - l - 1); i += 2) {
    cout << l + i << " " << l + i + 1 << endl;
  }
}
