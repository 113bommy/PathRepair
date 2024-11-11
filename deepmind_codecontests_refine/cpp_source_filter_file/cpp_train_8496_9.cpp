#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, x = 0;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    while (x > a) a += b;
    x = a;
  }
  cout << x;
}
