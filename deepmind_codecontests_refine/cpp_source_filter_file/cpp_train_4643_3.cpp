#include <bits/stdc++.h>
using namespace std;
string s, res;
int cur, was[1000 * 1000];
vector<int> p[300];
vector<char> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) p[s[i]].push_back(i);
  cur = 0;
  for (int ch = 'a'; ch <= 'z'; ch++) {
    for (int i = 0; i < p[ch].size(); i++) {
      if (p[ch][i] >= cur) {
        while (!st.empty() && st.back() < ch) {
          res += st.back();
          st.pop_back();
        }
        res += ch;
        was[p[ch][i]] = 1;
        for (int j = cur; j < p[ch][i]; j++) st.push_back(s[j]);
        cur = p[ch][i] + 1;
      }
    }
  }
  while (!st.empty()) res += st.back(), st.pop_back();
  cout << res;
}
