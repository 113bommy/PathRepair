#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
multiset<string> query(int l, int r);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  multiset<string> q_all = query(1, n);
  multiset<string> q_without_first = query(2, n);
  for (auto& s : q_without_first) {
    q_all.erase(q_all.find(s));
  }
  vector<string> first;
  for (auto& s : q_all) {
    first.push_back(s);
  }
  sort(first.begin(), first.end(), [&](const string& s1, const string& s2) {
    return s1.length() < s2.length();
  });
  string ans = "";
  multiset<char> used;
  for (auto& s : first) {
    for (auto& c : s) {
      if (used.find(c) == used.end()) {
        ans += c;
      } else {
        used.erase(used.find(c));
      }
    }
    for (auto& c : ans) {
      used.insert(c);
    }
  }
  cout << "! " << ans << endl;
}
multiset<string> query(int l, int r) {
  multiset<string> ans;
  int sz = (r - l + 1), cnt = (sz * (sz + 1)) / 2;
  if (cnt == 0) {
    return ans;
  }
  cout << "? " << l << ' ' << r << endl;
  for (int i = 0; i < cnt; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ans.insert(s);
  }
  return ans;
}
