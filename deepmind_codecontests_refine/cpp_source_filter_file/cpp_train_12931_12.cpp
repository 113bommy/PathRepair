#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n, m;
  string s[n], t[m];
  int i = 0;
  for (; i < n; i++) cin >> s[i];
  for (i = 0; i < m; i++) cin >> t[i];
  int q;
  cin >> q;
  int x;
  while (q--) {
    cin >> x;
    cout << s[(x - 1) % n] + t[(x - 1) % m] << "\n";
  }
}
