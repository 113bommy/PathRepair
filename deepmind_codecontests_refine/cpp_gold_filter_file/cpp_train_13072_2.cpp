#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), v(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int c = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    c += b[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == 1) continue;
    v[i] = 1;
    int t = a[i] - 1;
    while (t != i) {
      v[t] = 1;
      t = a[t] - 1;
    }
    r++;
  }
  int an = ((c % 2) ^ 1) + ((r == 1 ? 0 : r));
  cout << an << endl;
  return 0;
}
