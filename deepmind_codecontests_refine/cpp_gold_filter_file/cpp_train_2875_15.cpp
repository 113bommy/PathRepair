#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  if (k == n || !k) {
    cout << "0 0";
  } else {
    cout << "1 ";
    cout << min(2 * k, n - k);
  }
  return 0;
}
