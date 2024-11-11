#include <bits/stdc++.h>
using namespace std;
bool aabb, abab, abba;
int n, k;
string v = "aeiou";
bool isvowel(char c) {
  for (int i = 0; i < 5; ++i) {
    if (c == v[i]) return 1;
  }
  return 0;
}
void chg(string &s) {
  int cnt = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) {
    if (isvowel(s[i])) {
      if (++cnt == k) {
        s = s.substr(0, i + 1);
        return;
      }
    }
  }
  if (cnt < k) {
    puts("NO"), exit(0);
    ;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  aabb = abab = abba = 1;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    string s[4];
    for (int j = 0; j < 4; ++j) {
      cin >> s[j];
      chg(s[j]);
    }
    if (s[0] != s[1] || s[2] != s[2]) {
      aabb = 0;
    }
    if (s[0] != s[2] || s[1] != s[3]) {
      abab = 0;
    }
    if (s[0] != s[3] || s[1] != s[2]) {
      abba = 0;
    }
  }
  if (aabb && abab && abba) {
    puts("aaaa"), exit(0);
    ;
  }
  if (aabb) {
    puts("aabb"), exit(0);
  }
  if (abab) {
    puts("abab"), exit(0);
    ;
  }
  if (abba) {
    puts("abab"), exit(0);
    ;
  }
  puts("NO"), exit(0);
  ;
}
