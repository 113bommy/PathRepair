#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  s = 1;
  while (n > 0) {
    if (n % 2 == 1) s++;
    n = n / 2;
  }
  cout << s << endl;
}
