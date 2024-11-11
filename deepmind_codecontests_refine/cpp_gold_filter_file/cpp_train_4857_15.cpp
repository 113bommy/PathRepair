#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
string R;
int n;
struct st {
  string s;
  inline void shift(int x) {
    stack<char> _s;
    int c = 0;
    for (int i = int(n - x); i < int((int)s.size()); i++) _s.push(s[i]);
    for (int i = int(n - 1); i >= int(0); i--)
      if (i - x >= 0) s[i] = s[i - x];
    while (!_s.empty()) s[c++] = _s.top(), _s.pop();
  }
} wo;
inline void add(int k) {
  int quiebre = n;
  for (int i = int(0); i < int(n); i++)
    if (R[n - 1 - k] == wo.s[i]) quiebre = i;
  wo.shift(n);
  wo.shift(quiebre);
  wo.shift(1);
  ans.push_back(n);
  ans.push_back(quiebre);
  ans.push_back(1);
}
int main() {
  cin >> n;
  string s1;
  cin >> s1 >> R;
  wo.s = s1;
  int cnt[29];
  memset(cnt, 0, sizeof(cnt));
  for (int i = int(0); i < int(n); i++) cnt[s1[i] - 'a']++, cnt[R[i] - 'a']--;
  for (int i = int(0); i < int(26); i++)
    if (cnt[i] != 0) {
      cout << "-1" << endl;
      return 0;
    }
  for (int i = int(0); i < int(n); i++) add(i);
  cout << (int)ans.size() << endl;
  for (int i = int(0); i < int((int)ans.size()); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
