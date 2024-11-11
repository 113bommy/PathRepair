#include <bits/stdc++.h>
using namespace std;
int n, l, r, t, flag;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> l >> r;
    if (l > r) {
      cout << "No\n";
      continue;
    }
    flag = n / l;
    if (flag * r >= n)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
