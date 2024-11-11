#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int r = s[0] - 'a' + 1;
  int i = 1;
  int p = s[0];
  k--;
  while ((i != n) && k) {
    if (s[i] >= p + 2) {
      r = r + s[i] - 'a' + 1;
      k--;
      p = s[i];
    }
    i++;
  }
  if ((i >= n - 1) && k != 0)
    cout << -1;
  else
    cout << r;
  return 0;
}
