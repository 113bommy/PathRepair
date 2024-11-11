#include <bits/stdc++.h>
using namespace std;
int a, n = 0;
int main() {
  cin >> a;
  while (a) {
    if (a % 8 == 0) n++;
    a /= 8;
  }
  cout << n;
  return 0;
}
