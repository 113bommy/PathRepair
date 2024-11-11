#include <bits/stdc++.h>
using namespace std;
string s, t, st;
int m, r, l, k, x;
int main() {
  cin >> s >> m;
  while (m--) {
    cin >> r >> l >> k;
    t = s.substr(r - 1, l - r + 1);
    x = k % t.size();
    while (x--) {
      st += t.back();
      t.pop_back();
      st += t;
      t = st;
      st.clear();
    }
    for (int i = 0, j = r - 1; i < st.size() && j <= l - 1; i++, j++)
      s[j] = st[i];
  }
  cout << s << endl;
  return 0;
}
