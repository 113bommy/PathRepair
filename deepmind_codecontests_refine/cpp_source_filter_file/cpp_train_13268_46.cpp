#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, c, ct = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r >> c;
    if (r < c) ct++;
  }
  cout << ct;
  return 0;
}
