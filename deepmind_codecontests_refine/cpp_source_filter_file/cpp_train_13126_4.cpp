#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    c += x;
  }
  for (int i = 0; i < n; i++) {
    cin >> y;
    c -= y;
  }
  if (c >= 0)
    cout << "Yes";
  else
    cout << "N0";
  return 0;
}
