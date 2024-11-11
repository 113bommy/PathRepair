#include <bits/stdc++.h>
using namespace std;
int findMex(vector<int>& in) {
  unordered_set<int> all;
  for (int i : in) all.insert(i);
  for (int i = 0; i < in.size(); i++) {
    if (all.count(i) == 0) {
      return i;
    }
  }
  return in.size();
}
void solve() {
  string s, c;
  cin >> s >> c;
  for (int i = 0; i < s.size(); i++) {
    int index = -1;
    for (int j = i + 1; j < s.size(); j++) {
      if (s[i] <= s[j]) continue;
      if (index == -1)
        index = j;
      else {
        if (s[index] >= s[j]) index = j;
      }
    }
    if (index != -1) {
      swap(s[i], s[index]);
      break;
    }
  }
  if (s < c) {
    cout << s << endl;
    return;
  }
  cout << "---" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
