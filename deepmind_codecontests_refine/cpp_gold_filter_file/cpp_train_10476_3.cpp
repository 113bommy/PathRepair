#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length(), c = 0;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (s[i] == 'Q')
        a[i] = 1;
      else
        a[i] = 0;
    } else if (i > 0 && s[i] == 'Q')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1];
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A' && (a[i] == a[n - 1] || a[i] == 0)) {
      c += 0;
    } else if (s[i] == 'A') {
      c += (a[i] * (a[n - 1] - a[i]));
    }
  }
  cout << c << "\n";
  return 0;
}
