#include <bits/stdc++.h>
using namespace std;
stack<int> cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  for (int i = 0; i < signed(s.size()); i++) {
    if (s[i] == '1')
      cnt.push(i);
    else if (!cnt.empty())
      cnt.pop();
  }
  while (!cnt.empty()) {
    s[cnt.top()] = '0';
    cnt.pop();
  }
  cout << s << endl;
  return 0;
}
