#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r;
  cin >> l >> r;
  long long int mid = (r - l + 1) / 2;
  cout << "YES" << endl;
  while (mid--) {
    if (r >= l) {
      cout << l << " " << l + 1 << endl;
      l = l + 2;
    }
  }
}
