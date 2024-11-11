#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    int freq[26] = {0};
    int res = 0, distinct = 0;
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (freq[i] >= 2)
        res++;
      else if (freq[i] == 1) {
        distinct++;
      }
    }
    res += distinct / 2;
    cout << res << '\n';
  }
  return 0;
}
