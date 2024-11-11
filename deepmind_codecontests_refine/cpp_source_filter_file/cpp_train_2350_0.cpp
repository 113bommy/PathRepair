#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  long long n = s1.length();
  if (s1 == s2) {
    cout << 0;
    return 0;
  }
  unordered_map<char, char> ck;
  long long flag = 1;
  set<char> org;
  char arr[26] = {};
  for (long long i = 0; i < n; i++) {
    if (s1[i] != s2[i] &&
        (org.find(s1[i]) == org.end() && org.find(s2[i]) == org.end())) {
      if (ck.find(s1[i]) == ck.end() && ck.find(s2[i]) == ck.end()) {
        ck.insert({s1[i], s2[i]});
        if (arr[s2[i] - 'a'] != 0 || arr[s1[i] - 'a'] != 0) {
          flag = 0;
          break;
        } else {
          arr[s2[i] - 'a'] = 1;
          arr[s1[i] - 'a'] = 1;
        }
      } else {
        if (ck.find(s1[i]) != ck.end() && ck.find(s1[i])->second == s2[i])
          continue;
        else if (ck.find(s2[i]) != ck.end() && ck.find(s2[i])->second == s1[i])
          continue;
        else {
          flag = 0;
          break;
        }
      }
    } else if (s1[i] == s2[i] && ck.find(s1[i]) == ck.end() &&
               arr[s1[i]] == 0) {
      org.insert(s1[i]);
    } else {
      flag = 0;
      break;
    }
  }
  if (flag == 0)
    cout << -1;
  else {
    cout << ck.size() << "\n";
    for (auto c : ck) cout << c.first << " " << c.second << "\n";
  }
  return 0;
}
