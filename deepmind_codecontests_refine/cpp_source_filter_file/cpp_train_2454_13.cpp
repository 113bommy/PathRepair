#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("Text.txt");
  int i, j, k;
  long long n, a, b, c;
  cin >> a >> b >> c;
  for (i = a; i >= 1; i--) {
    if (2 * a <= b && 4 * a <= c) {
      cout << 7 * a << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
