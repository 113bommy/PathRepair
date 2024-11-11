#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 0, r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x < 0)
      l++;
    else
      r++;
  }
  if (l <= 1 || r <= 1)
    cout << "YES";
  else
    cout << "NO";
}
