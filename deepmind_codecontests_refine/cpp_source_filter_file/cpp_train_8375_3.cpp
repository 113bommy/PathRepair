#include <bits/stdc++.h>
using namespace std;
int main() {
  int ite;
  cin >> ite;
  while (ite--) {
    long long l, r;
    cin >> l >> r;
    long long k = l, prev = l;
    while (k < r) {
      prev = k;
      k = k | (k + 1);
    }
    cout << prev << endl;
  }
}
