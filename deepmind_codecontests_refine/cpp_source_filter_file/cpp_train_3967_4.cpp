#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  for (int i = 1; i < m - 1; ++i) {
    a += '5';
    b += '5';
  }
  a += '5';
  b += '6';
  cout << a << endl << b;
}
