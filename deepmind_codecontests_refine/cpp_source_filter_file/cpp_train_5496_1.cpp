#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  long digit = 0, s = 0;
  for (int i = 0; i < m; i++) {
    int d, c;
    cin >> d >> c;
    digit += c;
    s += d * c;
  }
  cout << digit - 1 + (s - 1) / 9 << endl;
}
