#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, p;
  cin >> n;
  string s[2 * n], s1, s2, m[2 * n];
  for (i = 0; i < 2 * n; i += 2) {
    cin >> s1 >> s2;
    s[i] = min(s1, s2);
    s[i + 1] = max(s1, s2);
  }
  for (i = 0; i < n; i++) {
    cin >> p;
    p--;
    p *= 2;
    m[i * 2] = s[p];
    m[i * 2 + 1] = s[p + 1];
  }
  for (i = 0; i < 2 * n - 2; i += 2) {
    if (m[i] < m[3])
      ;
    else if (m[i] < m[i + 2])
      swap(m[i + 1], m[i + 2]);
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
