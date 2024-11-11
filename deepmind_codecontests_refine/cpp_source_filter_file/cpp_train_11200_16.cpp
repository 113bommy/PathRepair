#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  string c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c[0] == 'T') s += 3;
    if (c[0] == 'C') s += 6;
    if (c[0] == 'O') s += 8;
    if (c[0] == 'D') s += 12;
    if (c[0] == 'I') s += 20;
  }
  cout << s;
}
