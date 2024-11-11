#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string s, t;
vector<pair<int, int> > seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  int pt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (pt == (int)t.size()) break;
    if (s[i] == t[pt]) {
      seg.push_back(make_pair(i, -pt - 1));
      pt++;
    }
  }
  if (pt < (int)t.size()) {
    cout << "No" << endl;
    return 0;
  }
  pt = (int)t.size() - 1;
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == t[pt]) {
      seg.push_back(make_pair(i, pt + 1));
      pt--;
    }
  }
  sort(seg.begin(), seg.end());
  pt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    while (pt < (int)seg.size() && seg[pt].first == i && seg[pt].second < 0) {
      cnt[t[-seg[pt].second - 1] - '0']++;
      pt++;
    }
    if (cnt[s[i] - '0'] == 0) {
      cout << "No" << endl;
      return 0;
    }
    while (pt < (int)seg.size() && seg[pt].first == i && seg[pt].second > 0) {
      cnt[t[seg[pt].second - 1] - '0']--;
      pt++;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
