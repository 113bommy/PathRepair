#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 2) {
    cout << "-1" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      cout << 15 << endl;
    else if (i == 2)
      cout << 10 << endl;
    else if (i == 3)
      cout << 6 << endl;
    else
      cout << 6 * (i - 2) << endl;
  }
}
