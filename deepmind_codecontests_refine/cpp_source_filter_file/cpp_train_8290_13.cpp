#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ss;
  cin >> s;
  map<string, int> m;
  for (int i = 0; i < 10; i++) {
    cin >> ss;
    m[ss] = i;
  }
  for (int i = 0; i < 80; i += 10) cout << m[s.substr(20, 10)];
  return 0;
}
