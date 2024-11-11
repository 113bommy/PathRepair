#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, bitf = 0, count = 0;
  cin >> n;
  vector<int> cnt(26, -1);
  for (i = 0; i < n - 1; i++) {
    char ch;
    string s;
    cin >> ch;
    cin >> s;
    if (bitf == 1) {
      if (ch != '.') count++;
      continue;
    }
    if (ch == '?')
      cnt[ch - 'a'] = 0;
    else if (ch == '.') {
      for (int j = 0; j < s.length(); j++) cnt[s[j] - 'a'] = 0;
    } else {
      vector<int> local(26, 0);
      for (int j = 0; j < s.length(); j++) local[s[j] - 'a']++;
      for (int j = 0; j < 26; j++)
        if (local[j] == 0) cnt[j] = 0;
      for (int j = 0; j < s.length(); j++)
        if (cnt[s[j] - 'a'] == -1) cnt[s[j] - 'a'] = 1;
    }
    int kn = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == -1 || cnt[i] == 1) kn++;
    }
    if (kn == 1) bitf = 1;
  }
  cout << count << endl;
  return 0;
}
