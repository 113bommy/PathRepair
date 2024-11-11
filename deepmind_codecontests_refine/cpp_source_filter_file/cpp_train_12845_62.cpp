#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    cout << "no solution\n";
    return 0;
  }
  int curx = 0;
  for (int i = n - 1; i >= 0; --i) {
    cout << curx << ' ' << 0 << '\n';
    curx += i;
  }
  return 0;
}
