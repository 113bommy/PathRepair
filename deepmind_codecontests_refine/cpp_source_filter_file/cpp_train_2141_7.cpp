#include <bits/stdc++.h>
using namespace std;
vector<int> W[26];
set<unsigned> S;
int main() {
  ios_base::sync_with_stdio(0);
  int m;
  string s;
  cin >> m >> s;
  for (unsigned i = 0; i < s.length(); ++i) W[s[i] - 'a'].push_back(i);
  int T[26] = {0};
  unsigned cur;
  bool add;
  for (int i = 0; i < 26; ++i) {
    cur = 0;
    auto x = S.lower_bound(m);
    auto j = lower_bound(W[i].begin(), W[i].end(), m);
    if (x != S.begin()) x--;
    if (j != W[i].begin()) j--;
    add = false;
    while (cur <= s.length() - m) {
      if (x != S.end() && *x < cur + m) {
        cur = *x + 1;
      } else if (j != W[i].end() && *j < cur + m) {
        cur = *j + 1;
        S.insert(*j);
      } else {
        add = true;
        break;
      }
      x = S.lower_bound(cur + m);
      j = lower_bound(W[i].begin(), W[i].end(), cur + m);
      if (x != S.begin() && *(prev(x)) > cur) x--;
      if (j != W[i].begin() && *(j - 1) > cur) j--;
    }
    if (add) {
      for (auto c : W[i]) S.insert(c);
    } else if (cur > s.length() - m)
      break;
  }
  for (auto x : S) T[s[x] - 'a']++;
  for (int i = 0; i < 26; ++i)
    while (T[i]--) cout << char('a' + i);
  return 0;
}
