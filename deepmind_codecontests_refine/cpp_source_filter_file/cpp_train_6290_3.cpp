#include <bits/stdc++.h>
using namespace std;
deque<string> v;
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  string s, str;
  cin >> s;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s[i] != '0') {
      string ss;
      if ((int)str.size()) {
        ss = s[i] + str;
        v.push_front(ss);
        str.clear();
      } else
        ss = s[i], v.push_front(ss);
    } else
      str.push_back('0');
  }
  string answer = v[0];
  int cnt = 1;
  for (int i = 1; i < (int)v.size(); ++i) {
    if ((int)answer.size() > (int)v[i].size())
      answer += v[i], ++cnt;
    else if ((int)answer.size() == (int)v[i].size() && answer > v[i])
      answer += v[i], ++cnt;
    else
      answer += v[i], cnt = 1;
  }
  cout << cnt << "\n";
  return 0;
}
