#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d, c, x = 0, a = 0;
  cin >> n >> b >> d;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c < b) {
      x += c;
    }
    if (x >= d) {
      a++;
      x = 0;
    }
  }
  cout << a;
  return 0;
}
