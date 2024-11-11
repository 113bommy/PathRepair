#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  int a, b;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'G')
      a = i;
    else if (s[i] == 'T')
      b = i;
  }
  int l = min(a, b);
  int r = max(a, b);
  if (r - l < k) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = l; i <= r; i += k) {
    if (s[i] == '#') {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
