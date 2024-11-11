#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<pair<int, int>, int> &p1,
         const pair<pair<int, int>, int> &p2) {
  if (p1.first.first == p2.first.first)
    return p1.first.second > p2.first.second;
  return p1.first.first < p2.first.first;
}
int main() {
  string s;
  cin >> s;
  set<long long> se;
  for (long long i = 1; i < 200000; i++) se.insert(i * i);
  long long res = 2e9 + 7;
  for (auto x : se) {
    string st, ans = "";
    stringstream ss;
    ss << x;
    ss >> st;
    if (st.length() > s.length()) break;
    for (int i = 0, j = 0; i < s.length(); i++) {
      if (s[i] == st[j]) j++, ans += s[i];
    }
    if (ans == st) res = min(res, (long long)(s.length() - st.length()));
  }
  cout << (res >= 2e9 ? -1 : res) << endl;
}
