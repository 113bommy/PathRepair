#include <bits/stdc++.h>
using namespace std;
string outputAns(string odds, string evens, vector<int> &freq) {
  string out = "";
  for (int i = 0; i < odds.length(); i++)
    for (int j = 1; j <= freq[odds[i] - 'a']; j++) out += string(1, odds[i]);
  for (int i = 0; i < evens.length(); i++)
    for (int j = 1; j <= freq[evens[i] - 'a']; j++) out += string(1, evens[i]);
  return out;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    vector<int> freq(26, 0);
    vector<bool> found(26, false);
    for (int i = 0; i < str.length(); i++) {
      freq[str[i] - 'a']++;
      found[str[i] - 'a'] = true;
    }
    string odds = "", evens = "";
    for (int i = 0; i < 26; i += 2)
      if (found[i]) odds += string(1, (char)'a' + i);
    for (int i = 1; i < 26; i += 2)
      if (found[i]) evens += string(1, (char)'a' + i);
    if (abs(odds[odds.length() - 1] - evens[0]) != 1)
      cout << outputAns(odds, evens, freq) << endl;
    else if (abs(odds[odds.length() - 1] - evens[evens.length() - 1]) != 1) {
      reverse(evens.begin(), evens.end());
      cout << outputAns(odds, evens, freq) << endl;
    } else if (abs(odds[0] - evens[0]) != 1) {
      reverse(odds.begin(), odds.end());
      cout << outputAns(odds, evens, freq) << endl;
    } else if (abs(odds[0] - evens[evens.length() - 1]) != 1) {
      reverse(evens.begin(), evens.end());
      reverse(odds.begin(), odds.end());
      cout << outputAns(odds, evens, freq) << endl;
    } else
      cout << "No Answer" << endl;
  }
  return 0;
}
