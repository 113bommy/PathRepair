#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, m = 0;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < h)
      m = +2;
    else
      m++;
  }
  cout << m << endl;
  return 0;
}
