#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n, a, s = 0;
  cin >> d >> n;
  while (--n) {
    cin >> a;
    s += d - a;
  }
  cout << s;
  return 0;
}
