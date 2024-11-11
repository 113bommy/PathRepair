#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int n = 0;
  while (a < b) {
    a = 3 * a;
    b = 2 * b;
    n++;
  }
  cout << n;
  return 0;
}
