#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;
long long reduce(string k) {
  vector<char> s;
  for (int j = 0; j < k.size(); j++) {
    if (!s.size()) {
      s.push_back(k[j]);
      continue;
    }
    if (k[j] == ')' && s[s.size() - 1] == '(')
      s.pop_back();
    else
      s.push_back(k[j]);
  }
  if (s.empty()) return 0;
  if (s[0] != s[s.size() - 1]) return INT_MAX;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      ans++;
    else
      ans--;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string k;
    cin >> k;
    long long t = reduce(k);
    if (t != INT_MAX) m[t]++;
  }
  long long ans = 0;
  if (m.count(0)) ans = m[0] * m[0];
  for (map<long long, long long>::iterator it = m.begin(); it != m.end();
       it++) {
    if (it->first == 0) break;
    if (m.count(-(it->first))) {
      ans += m[-(it->first)] * (it->second);
    }
  }
  cout << ans << endl;
}
