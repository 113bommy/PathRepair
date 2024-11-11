#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, d, s = 0;
  cin >> d >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (i < n - 1) s += d - a;
  }
  cout << s;
  return 0;
}
