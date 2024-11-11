#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  for (int i = 0; i < n - 1; i++) {
    a += '8';
    b += '1';
  }
  a += '9';
  b += '1';
  cout << a << endl << b;
}
