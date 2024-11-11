#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  int x, xprev, biggestdiff = 0;
  cin >> n >> c;
  cin >> xprev;
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    if (xprev - x > biggestdiff) biggestdiff = xprev - x;
    xprev = x;
  }
  if (biggestdiff - c <= 0)
    cout << "0";
  else
    cout << biggestdiff - c;
  return 0;
}
