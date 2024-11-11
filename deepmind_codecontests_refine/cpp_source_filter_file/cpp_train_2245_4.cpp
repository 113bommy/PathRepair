#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, z;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'G')
      x = i;
    else if (s[i] == 'T')
      z = i;
  if (z < x && (x - z) % k == 0)
    for (int j = x; j > z;) {
      j -= k;
      if (s[j] == '#') {
        cout << "NO\n";
        exit(0);
      }
      if (s[j] == '.') continue;
    }
  else if (x < z && (z - x) % k == 0)
    for (int j = z; j < x;) {
      j += k;
      if (s[j] == '#') {
        cout << "NO\n";
        exit(0);
      }
      if (s[j] == '.') continue;
    }
  else {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  return 0;
}
