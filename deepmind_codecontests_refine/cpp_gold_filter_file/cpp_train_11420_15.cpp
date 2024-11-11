#include <bits/stdc++.h>
using namespace std;
string s;
bool notpalin(int l, int r) {
  for (int i = l, j = r; i < j; i++, j--) {
    if (s[i] != s[j]) return true;
  }
  return false;
}
int main() {
  cin >> s;
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (notpalin(i, j)) res = max(res, j - i + 1);
    }
  }
  cout << res << endl;
}
