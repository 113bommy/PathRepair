#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, char> > a;
  set<char> skip;
  set<char> howmany;
  string s;
  cin >> s;
  int i, k;
  cin >> k;
  for (i = 97; i <= 122; i++) a.push_back({0, char(i)});
  for (i = 0; i < s.length(); i++) {
    a[int(s[i]) - 97].first++;
    howmany.insert(s[i]);
  }
  sort(a.begin(), a.end());
  i = 0;
  while (k - a[i].first >= 0) {
    if (a[i].first != 0) {
      k -= a[i].first;
      skip.insert(a[i].second);
    }
    i++;
  }
  int q = howmany.size() - skip.size();
  cout << max(0, q) << "\n";
  for (auto c : s) {
    if (skip.count(c) == 0) cout << c;
  }
}
