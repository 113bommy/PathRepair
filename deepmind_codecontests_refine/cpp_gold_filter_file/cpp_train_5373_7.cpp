#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k, i;
  while (cin >> s) {
    bool word[26] = {false};
    int count = 0;
    scanf("%d", &k);
    if (k > s.length()) {
      cout << "impossible" << endl;
      continue;
    }
    for (i = 0; i < s.length(); i++) {
      if (word[s[i] - 'a']) {
        continue;
      } else {
        word[s[i] - 'a'] = true;
        count++;
      }
    }
    cout << max(0, k - count) << endl;
  }
  return 0;
}
