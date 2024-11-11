#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, c, ct = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r >> c;
    if (c - r >= 2) ct++;
  }
  cout << ct;
  return 0;
}
