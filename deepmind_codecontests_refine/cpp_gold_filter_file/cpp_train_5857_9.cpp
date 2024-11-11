#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tc = 1;
int n, r;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n >> r;
    if (r < n)
      cout << 1LL * r * (r + 1) / 2 << "\n";
    else
      cout << 1LL * (n) * (n + 1) / 2 - n + 1 << "\n";
  }
  return 0;
}
