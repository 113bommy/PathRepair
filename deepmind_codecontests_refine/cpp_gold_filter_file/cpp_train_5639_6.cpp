#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b, d = 0, c = 0;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    c = c - a + b;
    d = max(d, c);
  }
  cout << d;
}
