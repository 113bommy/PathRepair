#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int odd = 0;
  while (a > 0) {
    if (a % 2 == 1) odd++;
    a /= 8;
  }
  cout << odd << endl;
}
