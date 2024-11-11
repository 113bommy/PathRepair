#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string sub, inp = "";
  while (cin >> sub) {
    inp += sub;
  }
  string s = "";
  for (int i = 0; i < (int)inp.size(); ++i) {
    if (inp[i] == 'a') {
      inp[i - 2] == '/' ? s += "A" : s += "a";
    } else if (inp[i] == 'r') {
      inp[i - 2] == '/' ? s += "R" : s += "r";
    } else if (inp[i] == 'd') {
      inp[i - 2] == '/' ? s += "D" : s += "d";
    }
  }
  vector<int> st, ans;
  for (int i = 0; i < static_cast<int>((s).size()); ++i) {
    if (s[i] == 'a') {
      st.push_back(0);
    } else if (s[i] == 'A') {
      ans.push_back(st.back());
      st.pop_back();
    } else if (s[i] == 'd') {
      st[static_cast<int>((st).size()) - 1]++;
    }
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}
