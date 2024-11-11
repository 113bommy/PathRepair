#include <bits/stdc++.h>
using namespace std;
const set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
bool is_consonant(char c) { return vowels.find(c) == vowels.end(); }
bool single_const(string s) {
  if (s.empty())
    return true;
  else {
    char c = s[0];
    for (auto& i : s)
      if (i != c) return false;
    return true;
  }
}
int main() {
  string s;
  cin >> s;
  vector<string> words = {};
  string cur_word = "";
  string cur_block = "";
  int const_count = 0;
  for (auto& c : s) {
    if (is_consonant(c)) {
      cur_block += c;
      const_count++;
    } else {
      cur_block = "";
      const_count = 0;
    }
    if (const_count < 3)
      cur_word += c;
    else if (single_const(cur_block)) {
      const_count = 1;
      cur_word += c;
    } else {
      words.push_back(cur_word);
      cur_word = c;
      cur_block = c;
      const_count = 1;
    }
  }
  words.push_back(cur_word);
  int len = words.size();
  cout << words[0];
  for (int i = 1; i < len; i++) cout << " " << words[i];
  return 0;
}
