#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << " " << 0 << "\n";
    return 0;
  }
  cout << min(n - k, 1) << " ";
  if (k < (n - 1) / 2)
    cout << min(k * 2, n - k);
  else
    cout << n - k;
}
