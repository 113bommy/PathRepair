#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  long long white = 0, black = 0;
  white = max(x - 1, y - 1);
  black = max(n - x, y - x);
  if (white <= black)
    cout << "White" << '\n';
  else
    cout << "Black" << '\n';
  return 0;
}
