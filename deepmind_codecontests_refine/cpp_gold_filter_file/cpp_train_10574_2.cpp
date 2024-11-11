#include <bits/stdc++.h>
using namespace std;
string s;
string bulbs = "BGRY";
int ans[4];
int getidx(char c) {
  if (c == 'R') return 0;
  if (c == 'B') return 1;
  if (c == 'Y') return 2;
  return 3;
}
int main() {
  cin >> s;
  do {
    bool ok = 1;
    for (int i = 0; i <= s.size() - 4 && ok; i += 4) {
      string sb = s.substr(i, 4);
      for (int j = 0; j < 4 && ok; j++) {
        if (sb[j] != '!' && sb[j] != bulbs[j]) ok = 0;
      }
    }
    if (ok) break;
  } while (next_permutation(bulbs.begin(), bulbs.end()));
  int i = 0;
  for (; i <= s.size() - 4; i += 4) {
    for (int j = i, k = 0; j < i + 4; j++, k++) {
      if (s[j] == '!') ans[getidx(bulbs[k])]++;
    }
  }
  int k = 0;
  for (; i < s.size(); i++, k++) {
    if (s[i] == '!') ans[getidx(bulbs[k])]++;
  }
  for (int i = 0; i < 4; i++) cout << ans[i] << " ";
}
