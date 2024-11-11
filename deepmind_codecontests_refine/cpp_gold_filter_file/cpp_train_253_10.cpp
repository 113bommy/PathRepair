#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size(), l = 0, r = 0, cnt, ind;
  for (int i = (0); i < int(n); i++) {
    l += (s[i] == '(');
    r += (s[i] == ')');
  }
  cnt = l - r;
  for (int i = (0); i < int(n); i++)
    if (s[i] == '#') ind = i;
  string cad;
  vector<int> ans;
  for (int i = (0); i < int(n); i++) {
    if (s[i] == '#') {
      if (cnt) {
        if (i == ind) {
          for (int j = (0); j < int(cnt); j++) cad += ')';
          ans.push_back(cnt);
        } else {
          cad += ')';
          cnt--;
          ans.push_back(1);
        }
      } else {
        cout << -1 << endl;
        return 0;
      }
    } else
      cad += s[i];
  }
  l = r = 0;
  for (int i = (0); i < int(cad.size()); i++) {
    l += (cad[i] == '(');
    r += (cad[i] == ')');
    if (r > l) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = (0); i < int(ans.size()); i++) cout << ans[i] << endl;
}
