#include <bits/stdc++.h>
using namespace std;
int likes[26], len;
long long pre[100100];
string s;
int getLikes(char ch) { return likes[ch - 'a']; }
int main() {
  for (int i = 0; i < 26; i++) {
    cin >> likes[i];
  }
  cin >> s;
  len = s.length();
  for (int i = 0; i < len; i++) {
    pre[i] = (i == 0 ? 0 : pre[i - 1]) + getLikes(s[i]);
  }
  long long ct = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    map<long long, int> seen;
    if (s[0] == ch) {
      seen.insert(make_pair(pre[0], 1));
    }
    for (int i = 1; i < len; i++) {
      if (s[i] != ch) {
        continue;
      }
      if (seen.find(pre[i - 1]) != seen.end()) {
        ct += (long long)seen[pre[i - 1]];
      }
      if (seen.find(pre[i]) == seen.end()) {
        seen.insert(make_pair(pre[i], 1));
      } else {
        seen[pre[i]]++;
      }
    }
  }
  cout << ct << '\n';
  return 0;
}
