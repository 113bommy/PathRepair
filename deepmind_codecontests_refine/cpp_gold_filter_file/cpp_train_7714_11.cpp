#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  for (long long i = l; i < r; i += 2) {
    long long aux = i + 1;
    cout << i << endl;
    cout << aux << endl;
  }
  return 0;
}
