#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int t, g;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'T') {
      t = i;
    }
    if (s[i] == 'G') {
      g = i;
    }
  }
  if (t < g) {
    for (int i = t; i < s.size(); i += k) {
      if (s[i] == '#') {
        cout << "NO";
        return 0;
      }
      if (s[i] == 'G') {
        cout << "YES";
        return 0;
      }
    }
  } else if (t > g) {
    for (int i = t; i >= 0; i -= k) {
      if (s[i] == '#') {
        cout << "NO";
        return 0;
      }
      if (s[i] == 'G') {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
