#include <bits/stdc++.h>
using namespace std;
int n;
string s[80000];
unordered_map<string, int> substrings;
int main(void) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    unordered_map<string, bool> used;
    for (int j = 1; j <= s[i].size(); ++j) {
      for (int k = 0; k + j <= s[i].size(); ++k) {
        string substring = s[i].substr(k, j);
        if (used.find(substring) == used.end()) {
          used[substring] = true;
          if (substrings.find(substring) == substrings.end()) {
            substrings[substring] = 1;
          } else {
            substrings[substring] += 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < s[i].size(); ++j) {
      for (int k = 0; k + j <= s[i].size(); ++k) {
        if (substrings[s[i].substr(k, j)] == 1) {
          cout << s[i].substr(k, j) << endl;
          goto van;
        }
      }
    }
  van:;
  }
  return 0;
}
