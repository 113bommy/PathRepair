#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> perm(n);
  for (int i = 0; i < n; i++) {
    cin >> perm[i];
  }
  int eve = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      eve += perm[j] < perm[i];
    }
  }
  int m;
  cin >> m;
  bool ok = !(eve % 2);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    int k = l - r + 1;
    k /= 2;
    if (k % 2) {
      cout << (ok ? "even" : "odd") << '\n';
    } else {
      ok = !ok;
      cout << (ok ? "even" : "odd") << '\n';
    }
  }
}
