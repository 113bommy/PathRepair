#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int a, b, c;
  cin >> n;
  a = 1;
  b = 2;
  c = n - 3;
  if (c % 3) {
    c++;
    b--;
  }
  cout << a << " " << b << " " << c;
  return 0;
}
