#include <bits/stdc++.h>
using namespace std;
int nTest;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> nTest;
  for (int iTest = 1; iTest <= nTest; ++iTest) {
    cin >> s;
    string res = "";
    int rock = 0;
    int paper = 0;
    int scissors = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R') {
        rock++;
      } else if (s[i] == 'P') {
        paper++;
      } else {
        scissors++;
      }
    }
    int maxCnt = max(rock, paper);
    maxCnt = max(maxCnt, scissors);
    if (rock == paper && rock == scissors) {
      cout << s << "\n";
    } else {
      if (maxCnt == rock) {
        for (int i = 0; i < s.size(); ++i) {
          res += 'P';
        }
      } else if (maxCnt == paper) {
        for (int i = 0; i < s.size(); ++i) {
          res += 'S';
        }
      } else {
        for (int i = 0; i < s.size(); ++i) {
          res += 'R';
        }
      }
      cout << res << "\n";
    }
  }
  return 0;
}
