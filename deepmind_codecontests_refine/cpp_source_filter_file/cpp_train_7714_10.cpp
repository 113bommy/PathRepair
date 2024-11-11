#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  int sz = (r - l + 1) / 2;
  cout << "YES" << endl;
  int i = 1;
  while (sz--) {
    cout << i << " " << i + 1 << endl;
    i += 2;
  }
}
