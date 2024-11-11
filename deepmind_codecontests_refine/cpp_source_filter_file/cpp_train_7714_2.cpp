#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  long long c = (r - l + 1) / 2;
  long i = l;
  cout << "YES" << endl;
  while (c--) {
    cout << i << " " << i + 1 << endl;
    i += 2;
  }
  return 0;
}
