#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  if (n == 1)
    cout << "1";
  else if (n == 2)
    cout << "2";
  else {
    while (n >= 0) {
      s = s + 2;
      n = n - 2;
    }
    cout << s;
  }
  return 0;
}
