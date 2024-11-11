#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, mx;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    mx = max(mx, c);
  }
  cout << mx;
  return 0;
}
