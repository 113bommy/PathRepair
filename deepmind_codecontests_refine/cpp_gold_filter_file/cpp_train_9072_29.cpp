#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << (n + 2) / 2 << "\n";
  int x = 1, y = 1;
  for (int k = 1; k <= n; k++) {
    cout << x << " " << y << "\n";
    if (x < (n + 2) / 2)
      x++;
    else
      y++;
  }
  return 0;
}
