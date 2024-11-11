#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l, r;
  for (int ii = 0; ii < n; ii++) {
    int i;
    cin >> i;
    if (i == 0)
      l = ii + 1;
    else
      r = ii + 1;
  }
  cout << min(l, r);
}
