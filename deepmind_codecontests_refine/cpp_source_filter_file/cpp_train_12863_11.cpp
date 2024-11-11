#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, c, d, e;
  string a;
  cin >> a >> b;
  d = 1;
  c = a[a.size() - 1] - '0';
  for (int i = 0; i < 9; i++) {
    c = c * d;
    if (e % 10 == b || c % 10 == 0) break;
    c = c / d;
    d++;
  }
  cout << d;
  return 0;
}
