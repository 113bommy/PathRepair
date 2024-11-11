#include <bits/stdc++.h>
using namespace std;
long long l, r = 1e9, m;
int i, n;
string t;
char c;
int main() {
  cin >> n;
  cout << 1 << " " << r << "\n";
  cin >> t;
  c = t[0];
  m = (l + r) / 2;
  for (i = 1; i < n; i++) {
    cout << 1 << " " << m << "\n";
    cin >> t;
    if (t[0] == c) {
      r = m;
    } else {
      l = m;
    }
    m = (r + l) / 2;
  }
  cout << 0 << " " << m + 1 << " " << 2 << " " << m - 1 << "\n";
}
