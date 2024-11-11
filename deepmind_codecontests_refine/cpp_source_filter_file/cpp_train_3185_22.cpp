#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int a, b;
  cin >> a >> b;
  while (a < b) {
    b *= 2;
    a *= 3;
    n++;
  }
  cout << n;
}
