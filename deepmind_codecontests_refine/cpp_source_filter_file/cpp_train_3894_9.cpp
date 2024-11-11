#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int r, g, b;
  cin >> r >> g >> b;
  long long int ans = r / 3 + g / 3 + b / 3, ans1 = 0, ans2 = 0;
  if (r >= 1 && g >= 1 && b >= 1)
    ans1 = max(ans, 1 + (r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3);
  if (r >= 2 && g >= 2 && b >= 2)
    ans2 = max(ans1, 2 + (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3);
  cout << ans2 << endl;
}
