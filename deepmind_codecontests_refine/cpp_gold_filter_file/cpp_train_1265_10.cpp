#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int x = (n - k) / 2 + 1;
  for (int i = 1; i <= n; i++) {
    if (i % x == 0) {
      cout << '1';
    } else
      cout << '0';
  }
  cout << endl;
  return 0;
}
