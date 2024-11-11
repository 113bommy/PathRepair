#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j;
  cin >> i >> j;
  cout << "YES" << '\n';
  while (i < j) {
    cout << i << " " << i + 1 << '\n';
    i += 2;
  }
  return 0;
}
