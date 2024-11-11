#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  long long p, c, n, i;
  cin >> s;
  n = s.size();
  c = 0;
  p = s.find('^');
  for (i = 0; i < n; i++) {
    c += (p - i) * ((isdigit(s[i])) ? (s[i] - '0') : 0);
  }
  if (c == 0)
    cout << "balance";
  else if (c < 0)
    cout << "right";
  else
    cout << "left";
  return 0;
}
