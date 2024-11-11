#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a >> s;
  sort(s.begin(), s.end(), greater<char>());
  int n, m;
  n = a.size();
  m = s.size();
  int i, j = 0;
  for (i = 0; i < n; i++) {
    if (int(s[j]) > int(a[i])) {
      a[i] = s[j];
      j++;
    }
    cout << a[i];
    if (s[j] == '0' || j == m - 1) break;
  }
  i++;
  while (i < n) {
    cout << a[i];
    i++;
  }
  return 0;
}
