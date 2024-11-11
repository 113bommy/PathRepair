#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (char c : s) {
    cnt[c - 'a']++;
  }
  string ans;
  int k = 0;
  string t;
  for (char c : s) {
    while (cnt[k] == 0) {
      k++;
    }
    while (!t.empty() && t.back() - 'a' <= k) {
      ans += t.back();
      t.pop_back();
    }
    if (c - 'a' == k) {
      ans += c;
    } else {
      t.push_back(c);
    }
    cnt[c - 'a']--;
  }
  while (!t.empty()) {
    ans += t.back();
    t.pop_back();
  }
  cout << ans << endl;
}
