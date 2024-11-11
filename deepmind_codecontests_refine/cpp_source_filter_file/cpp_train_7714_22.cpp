#include <bits/stdc++.h>
using namespace std;
int main() {
  long int l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  for (long int i = l; i < r; i += 2) {
    cout << i << " " << 1 + i << endl;
  }
  return 0;
}
