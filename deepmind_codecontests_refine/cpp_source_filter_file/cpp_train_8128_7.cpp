#include <bits/stdc++.h>
using namespace std;
bool a[26];
long long int b[26];
map<long long int, long long int> m;
string s;
long long int k;
int main() {
  cin >> s >> k;
  for (int i = 0; i < s.length(); i++) {
    b[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (b[i]) m.insert(make_pair(b[i], i));
  }
  long long int sum = 0;
  for (auto j = m.begin(); j != m.end(); j++) {
    sum += (j->first);
    if (sum <= k)
      a[j->second] = true;
    else {
      sum -= (j->first);
      break;
    }
  }
  set<char> c;
  for (int i = 0; i < s.length(); i++) {
    if (!a[s[i] - 'a']) c.insert(s[i]);
  }
  cout << c.size() << endl;
  for (int i = 0; i < s.length(); i++) {
    if (!a[s[i] - 'a']) cout << s[i];
  }
  cout << endl;
  return 0;
}
