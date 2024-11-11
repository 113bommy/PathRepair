#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
vector<string> split(const string &str, char sep) {
  vector<string> v;
  auto beg = str.begin();
  while (beg != str.end()) {
    auto end = beg;
    while (end != str.end() && *end != sep) ++end;
    v.push_back(string(beg, end));
    if (end != str.end()) ++end;
    beg = end;
  }
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2;
  cin >> s1 >> s2;
  vector<string> v1 = split(s1, ':');
  vector<string> v2 = split(s2, ':');
  int m1 = stoi(v1[0]) * 60 + stoi(v1[1]);
  int m2 = stoi(v2[0]) * 60 + stoi(v2[1]);
  int diff = m2 - m1;
  diff /= 2;
  int hh = diff / 60, mm = diff % 60;
  int ans1 = stoi(v1[0]) + hh, ans2 = stoi(v1[1]) + mm;
  if (ans2 >= 60) {
    ans2 -= 60;
    ++ans1;
  }
  cout << setfill('0') << right << setw(2) << ans1 << ':' << setfill('0')
       << right << setw(2) << ans2 << '\n';
  return 0;
}
