#include <bits/stdc++.h>
using namespace std;
string s;
string tmp;
int m;
int l, r, k;
int main() {
  cin >> s >> m;
  while (m--) {
    cin >> l >> r >> k;
    k %= (r - l + 1);
    tmp = s.substr(r - k, k);
    s.erase(r - k, k);
    s.insert(l - 1, tmp);
  }
  cout << s << endl;
  return 0;
}
