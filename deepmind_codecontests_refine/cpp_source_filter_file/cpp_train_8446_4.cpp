#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
bool isSuffix(string w, string b) {
  if (w.size() < b.size()) return false;
  int j = b.size() - 1;
  int i = w.size() - 1;
  while (j >= 0 && i >= 0) {
    if (w[i] != b[j]) {
      return false;
    }
    i--;
    j--;
  }
  return true;
}
int isAdjective(string w) {
  string target[] = {"lios", "liala"};
  for (int i = 0; i < 2; i++) {
    if (isSuffix(w, target[i])) return (i + 1);
  }
  return 0;
}
int isNoun(string w) {
  string target[] = {"etr", "etra"};
  for (int i = 0; i < 2; i++) {
    if (isSuffix(w, target[i])) return (i + 1);
  }
  return 0;
}
int isVerb(string w) {
  string target[] = {"initis", "inites"};
  for (int i = 0; i < 2; i++) {
    if (isSuffix(w, target[i])) {
      return (i + 1);
    }
  }
  return 0;
}
int main() {
  string w;
  vector<string> words;
  while (cin >> w) {
    words.push_back(w);
  }
  if (words.size() == 1) {
    int valid = isNoun(words[0]) | isVerb(words[0]) | isAdjective(words[0]);
    if (valid)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  int bit = 0;
  for (int i = 0; i < words.size(); i++) {
    int cur = isNoun(words[0]) | isVerb(words[0]) | isAdjective(words[0]);
    bit = bit | cur;
    if (!cur) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (!bit || bit == 3) {
    cout << "NO" << endl;
    return 0;
  }
  int stage = 0;
  for (int i = 0; i < words.size(); i++) {
    if (stage == 0) {
      if (isAdjective(words[i])) continue;
      if (isNoun(words[i])) {
        stage = 1;
        continue;
      }
      cout << "NO" << endl;
      return 0;
    }
    if (stage == 1) {
      if (!isVerb(words[i])) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (!stage) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
