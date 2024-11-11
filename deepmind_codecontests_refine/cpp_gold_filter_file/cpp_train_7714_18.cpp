#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  int sz = (r - l + 1) / 2;
  cout << "YES" << endl;
  long long i = l;
  while (sz--) {
    cout << i << " " << i + 1 << endl;
    i += 2;
  }
}
