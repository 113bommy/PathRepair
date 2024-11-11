#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  while (n--) cin >> s;
  bool wall = false;
  int segments, i = 0;
  while (i < s.size()) {
    if (!wall && s[i] == 'B') {
      segments++;
      wall = true;
    } else if (wall && s[i] == '.') {
      wall = false;
    }
    i++;
  }
  cout << segments << endl;
  return 0;
}
