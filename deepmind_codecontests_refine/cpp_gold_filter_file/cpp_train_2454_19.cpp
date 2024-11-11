#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("Text.txt");
  int i, j, k;
  long long n, a, b, c;
  cin >> a >> b >> c;
  for (i = a; i >= 1; i--) {
    if (2 * i <= b && 4 * i <= c) {
      cout << 7 * i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
