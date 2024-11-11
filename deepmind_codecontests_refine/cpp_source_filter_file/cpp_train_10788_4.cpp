#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > 0) c++;
  }
  if (c >= n - 1 || c == 1)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
