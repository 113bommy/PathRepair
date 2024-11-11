#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, m = 0;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a <= h)
      m = +1;
    else
      m += 2;
  }
  cout << m;
  return 0;
}
