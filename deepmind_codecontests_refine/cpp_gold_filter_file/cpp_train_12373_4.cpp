#include<bits/stdc++.h>
using namespace std;
int main() {
  vector<int> cnt[256];
  vector<char> alp(26);
  iota(alp.begin(), alp.end(), 'a');
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (char c : alp) {
      cnt[c].push_back(count(s.begin(), s.end(), c));
    }
  }
  for (char c : alp) {
    cout << string(*min_element(cnt[c].begin(), cnt[c].end()), c);
  }
  cout << endl;
}