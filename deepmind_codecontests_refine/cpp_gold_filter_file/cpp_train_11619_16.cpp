#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int l, r, x;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> x;
    int less = 0;
    for (int j = l - 1; j < r; j++) {
      if (p[j] <= p[x - 1]) less++;
    }
    if (less == (x - l + 1))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
