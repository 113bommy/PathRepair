#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int t = 1;
  if (s[0] != 'a') {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i + 1] - s[i] > t) {
      cout << "NO\n";
      return 0;
    }
    if (s[i + 1] - s[i] == t) t++;
  }
  cout << "YES\n";
  return 0;
}
