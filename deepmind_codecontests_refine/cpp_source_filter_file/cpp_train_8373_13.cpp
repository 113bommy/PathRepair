#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  map<char, int> mp;
  map<char, int> mp1;
  int result = 0;
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == ' ') mp[s1[i]]++;
  }
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == ' ') mp1[s2[i]]++;
  }
  map<char, int>::iterator it;
  bool flag = true;
  for (it = mp1.begin(); it != mp1.end(); it++) {
    char ch = it->first;
    int cnt2 = it->second;
    int cnt1 = 0;
    if (mp1.count(ch)) cnt1 = mp[ch];
    if (cnt1 < cnt2) {
      flag = false;
      break;
    }
  }
  if (flag == true)
    puts("YES");
  else
    puts("NO");
  return 0;
}
