#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int l = -1, r = -1;
  for (int i = s.size() - 2; i >= 0; i--) {
    if (s[i] > s[i + 1]) {
      l = i;
      r = i + 1;
      break;
    }
  }
  if (l == -1)
    cout << "NO"
         << "\n";
  else {
    cout << "YES"
         << "\n";
    cout << l + 1 << " " << r + 1 << "\n";
  }
  return 0;
}
