#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int r = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (r == 0 && t == -1)
      c++;
    else if (t == 1)
      r++;
    else if (r > 0 && t == -1)
      r--;
  }
  cout << c;
}
