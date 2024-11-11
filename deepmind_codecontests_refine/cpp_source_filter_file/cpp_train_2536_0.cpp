#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const int INF = 1000000000;
const int mod = 1000000007;
int main() {
  string s;
  cin >> s;
  if (s[0] == 'f') {
    for (int(i) = (0); (i) < (3); ++(i)) {
      cout << s[0];
      s.erase(s.begin());
    }
  } else {
    for (int(i) = (0); (i) < (4); ++(i)) {
      cout << s[0];
      s.erase(s.begin());
    }
  }
  cout << "://";
  for (int(i) = (0); (i) < (s.size()); ++(i))
    if (s[i] == 'r' && s[i + 1] == 'u') {
      for (int(j) = (0); (j) < (i); ++(j)) cout << s[j];
      cout << '.';
      cout << "ru";
      if (i + 2 != s.size()) {
        cout << '/';
        for (int(j) = (i + 2); (j) < (s.size()); ++(j)) cout << s[j];
      }
      cout << endl;
      return 0;
    }
  return 0;
}
