#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100100];
int t[100100];
int maxl[100100];
void read_data() {
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    bool good = true;
    t[i + (n - 1) * m] = 1;
    for (int j = n - 1; j > 0; j--) {
      if (a[i + j * m] >= a[i + (j - 1) * m])
        t[i + (j - 1) * m] = t[i + j * m] + 1;
      else
        t[i + (j - 1) * m] = 1;
      maxl[j] = max(maxl[j], t[i + j * m]);
    }
    maxl[0] = max(maxl[0], t[0]);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (maxl[l] >= (r - l + 1))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
void solve() {}
int main() {
  read_data();
  solve();
  return 0;
}
