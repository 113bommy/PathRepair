#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, r, L, R;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    L = c - r;
    R = c + r;
    if (L < a and R > a and R < b)
      cout << abs(a - b) - abs(R - a) << "\n";
    else if (R > b and L > a and L < b)
      cout << abs(a - b) - abs(b - L) << "\n";
    else if (L >= a and R <= b)
      cout << abs(a - b) - abs(L - R) << "\n";
    else if (L <= a and R >= b)
      cout << 0 << "\n";
    else
      cout << abs(a - b) << "\n";
  }
}
