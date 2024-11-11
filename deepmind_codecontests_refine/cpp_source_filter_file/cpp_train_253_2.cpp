#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cont = 0, ultimo, f = 0, curr = 0;
  int balance[s.size()];
  vector<int> ans;
  for (int i = (0); i < (s.size()); i++) {
    curr = (s[i] == ')') ? curr - 1 : (s[i] == '(') ? curr + 1 : curr;
    balance[i] = curr;
    if (s[i] == '#') {
      cont++;
      ans.push_back(1);
    }
  }
  ans.back() = balance[s.size() - 1] - cont + 1;
  int j = 0;
  curr = 0;
  for (int i = (0); i < (s.size()); i++) {
    if (s[i] == '(')
      curr++;
    else if (s[i] == ')')
      curr--;
    else
      curr -= ans[j++];
    if (curr < 0) f = 1;
  }
  if (curr > 0 or ans.back() == 0) f = 1;
  if (f)
    puts("-1");
  else
    for (int i = (0); i < (ans.size()); i++) cout << ans[i] << endl;
}
