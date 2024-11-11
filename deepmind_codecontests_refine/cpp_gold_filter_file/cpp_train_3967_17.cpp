#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  for (int i = 1; i < 2000; ++i) {
    a += '4';
    b += '5';
  }
  a += '5';
  b += '5';
  cout << a << endl << b;
}
