#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long temp = 0;
pair<long long, long long> f(string s, int pos) {
  long long ans = 1;
  while (s[pos + 1] == '*')
    if (s[pos] != '&')
      ans *= s[pos] - '0', pos += 2;
    else
      ans *= temp, pos += 2;
  if (s[pos] != '&')
    ans *= s[pos] - '0';
  else
    ans *= temp;
  return make_pair(ans, pos);
}
long long cal(string s) {
  long long ans = 0;
  for (long long i = 0; i < s.length(); i++)
    if (s[i] != '*' && s[i] != '+') {
      if (s[i + 1] == '+') {
        if (s[i] != '&')
          ans += s[i] - '0';
        else
          ans += temp;
      } else {
        pair<long long, long long> p = f(s, i);
        ans += p.first;
        i = p.second;
      }
    }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s;
  long long ans = cal(s);
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '*') v.push_back(i);
  for (int i = 0; i < v.size(); i++)
    for (int j = v[i] + 1; j < s.length(); j += 2)
      temp = cal(s.substr(v[i] + 1, j - v[i])),
      ans = max(ans, cal(s.substr(0, v[i] + 1) + '&' +
                         s.substr(j + 1, s.length() - j)));
  for (int i = 0; i < v.size(); i++)
    for (int j = v[i] - 1; j >= 0; j -= 2)
      temp = cal(s.substr(j, v[i] - j)),
      ans = max(ans,
                cal(s.substr(0, j) + '&' + s.substr(v[i], s.length() - v[i])));
  cout << ans;
}
