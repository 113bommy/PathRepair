#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, d = 0, c;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    c = c - a + b;
    d = max(d, c);
  }
  cout << d;
}
