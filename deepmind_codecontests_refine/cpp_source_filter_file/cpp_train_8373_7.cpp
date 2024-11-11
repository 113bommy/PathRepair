#include <bits/stdc++.h>
using namespace std;
void weza() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  weza();
  string st, s, t = "";
  getline(cin, st);
  bool b = 1;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      if (st.find(s[i]) >= st.size())
        b = 0;
      else
        st.erase(st.find(s[i]), t.size());
    }
  }
  if (b == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
