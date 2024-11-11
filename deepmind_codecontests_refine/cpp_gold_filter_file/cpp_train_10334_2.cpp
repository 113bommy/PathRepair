#include <bits/stdc++.h>
using namespace std;
set<char> s = {'a', 'e', 'i', 'o', 'u'};
bool scheme[3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string poem[5];
  bool found;
  int vow = 0;
  scheme[0] = scheme[1] = scheme[2] = true;
  for (int klk = 1; klk <= n; klk++) {
    for (int i = 1; i <= 4; i++) {
      cin >> poem[i];
      found = false;
      vow = 0;
      for (int j = poem[i].length() - 1; j > -1; j--) {
        if (s.find(poem[i][j]) != s.end()) {
          vow++;
        }
        if (vow == k) {
          poem[i] = poem[i].substr(j, poem[i].length() - j + 1);
          found = true;
          break;
        }
      }
    }
    if (!found) {
      cout << "NO\n";
      return 0;
    }
    scheme[0] = scheme[0] && (poem[1] == poem[2]) && (poem[3] == poem[4]);
    scheme[1] = scheme[1] && (poem[1] == poem[3]) && (poem[2] == poem[4]);
    scheme[2] = scheme[2] && (poem[1] == poem[4]) && (poem[2] == poem[3]);
  }
  if (scheme[1] && scheme[0] && scheme[2]) {
    cout << "aaaa\n";
  } else if (scheme[0])
    cout << "aabb\n";
  else if (scheme[1])
    cout << "abab\n";
  else if (scheme[2])
    cout << "abba\n";
  else
    cout << "NO\n";
  return 0;
}
