#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k, nn;
  cin >> n;
  vector<int> a(n);
  if ((n % 4) == 2)
    cout << "-1\n";
  else if ((n % 4) == 2)
    cout << "-1\n";
  else {
    nn = n;
    for (i = 0; i < n / 2; i += 2) {
      a[i] = i + 2;
      a[n - 1 - i] = n + 1 - a[i];
      a[i + 1] = nn;
      a[n - 1 - (i + 1)] = n + 1 - a[i + 1];
      nn -= 2;
    }
    if ((n % 4) == 1) a[n / 2] = (n + 1) / 2;
    for (auto p : a) cout << p << " ";
    cout << "\n";
  }
  return 0;
}
