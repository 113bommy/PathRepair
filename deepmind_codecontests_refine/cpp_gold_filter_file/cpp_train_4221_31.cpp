#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, r = 0;
  cin >> a;
  while (a) {
    r += (a % 8 == 1);
    a /= 8;
  }
  cout << r << endl;
  return 0;
}
