#include <bits/stdc++.h>
using namespace std;
set<int> ans1, ans2;
int x1, x2;
void rec(int i, int x) {
  ans1.insert(x);
  if (x1 == x2) {
    ans2.insert(x);
  }
  if (i == 9) {
    return;
  }
  rec(i + 1, x * 10 + x1);
  rec(i + 1, x * 10 + x2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, k;
  cin >> t;
  for (x1 = 0; x1 <= 9; x1++) {
    for (x2 = 0; x2 <= 9; x2++) {
      rec(0, 0);
    }
  }
  while (t--) {
    cin >> n >> k;
    if (n == 1e9) {
      if (k == 2)
        cout << n << "\n";
      else
        cout << "111111111\n";
      continue;
    }
    if (k == 1) {
      cout << (*ans2.lower_bound(n)) << "\n";
    } else {
      cout << (*ans1.lower_bound(n)) << "\n";
    }
  }
}
