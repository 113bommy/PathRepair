#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int bal = 0;
  long long ans = 0;
  set<pair<int, int> > st;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '?') {
      int po, pc;
      cin >> po >> pc;
      s[i] = ')';
      st.insert(pair<int, int>(po - pc, i));
      ans += pc;
    }
    bal += (s[i] == '(') ? 1 : -1;
    if (bal < 0) {
      if (st.size() == 0) {
        cout << -1 << endl;
        return 0;
      }
      pair<int, int> ch = *st.begin();
      st.erase(st.begin());
      ans += ch.first;
      s[ch.second] = '(';
      bal += 2;
    }
  }
  bal = 0;
  for (int i = s.length() - 1; i >= 0; i++) {
    bal += (s[i] == '(') ? 1 : -1;
    if (bal < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl << s << endl;
  {
    int n;
    cin >> n;
  }
  return 0;
}
