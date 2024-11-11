#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  string S;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> S;
    if (S == "--x" || S == "x--")
      x--;
    else
      x++;
  }
  cout << x;
  return 0;
}
