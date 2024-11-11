#include <bits/stdc++.h>
using namespace std;
string st;
long ps;
long fl;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> st;
  cout << st[0];
  ps = 1;
  while (ps < st.size()) {
    if (fl == 0 && ps + 1 < st.size() && st[ps] == 'a' && st[ps + 1] == 't') {
      cout << "@";
      ps += 2;
      fl = 1;
    } else if (ps + 3 < st.size() && st[ps] == 'd' && st[ps + 1] == 'o' &&
               st[ps + 2] == 't') {
      cout << ".";
      ps += 3;
    } else {
      cout << st[ps];
      ++ps;
    }
  }
  cout << endl;
  cin.get();
  cin.get();
  return 0;
}
