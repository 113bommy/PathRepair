#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, mx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    mx = max(mx, c);
  }
  cout << mx;
  return 0;
}
