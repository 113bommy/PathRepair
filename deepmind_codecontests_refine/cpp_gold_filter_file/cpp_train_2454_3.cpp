#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, cou = 0;
  cin >> a >> b >> c;
  for (int i = a; i >= 1; i--) {
    if (i * 2 <= b && i * 4 <= c && i <= a) {
      cout << i + i * 2 + i * 4 << endl;
      return 0;
    }
  }
  cout << "0";
  return 0;
}
