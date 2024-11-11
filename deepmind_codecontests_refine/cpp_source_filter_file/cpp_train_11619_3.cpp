#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < int(n); i++) cin >> p[i];
  for (int i = 0; i < int(m); i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l -= 1;
    r -= 1;
    x -= 1;
    int pos = 0;
    for (int i = l; i <= x; i++) {
      if (p[i] < p[x]) {
        pos += 1;
      }
    }
    if (pos == x) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
