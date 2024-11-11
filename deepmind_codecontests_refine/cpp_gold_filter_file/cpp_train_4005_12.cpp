#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, l, r;
  cin >> n;
  while (n--) {
    cin >> l >> r;
    while ((l | l + 1) <= r) {
      l = l | (l + 1);
    }
    cout << l << endl;
  }
  return 0;
}
