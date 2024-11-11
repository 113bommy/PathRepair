#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
string word;
vector<string> words;
vector<vector<long long> > hshs;
map<long long, int> gd;
map<long long, pair<long long, int> > hashes;
bool bad(char c) {
  if (c == '.' || c == ',' || c == ' ' || c == '?' || c == '!' || c == 39 ||
      c == '-')
    return true;
  return false;
}
vector<long long> getHash(string second) {
  vector<long long> ans;
  long long hsh = 0, c = 31, cc = 1;
  for (int i = 0; i < second.size(); i++) {
    second[i] -= 'a';
    second[i]++;
    hsh += cc * second[i];
    ans.push_back(hsh);
    cc *= c;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  int sum = 0;
  string second;
  while (getline(cin, second)) {
    sum++;
    string curWord;
    for (int i = 0; i < second.size(); i++) {
      if (bad(second[i])) {
        sum++;
        if (curWord.size()) {
          words.push_back(curWord);
          curWord.clear();
        }
      } else {
        curWord += second[i];
      }
    }
    if (curWord.size()) {
      words.push_back(curWord);
    }
  }
  for (int i = 0; i < words.size(); i++) {
    hshs.push_back(getHash(words[i]));
  }
  for (int i = 0; i < words.size(); i++) {
    sum++;
    int ptr = 1;
    while (ptr < words[i].size()) {
      long long curHash = hshs[i][ptr - 1];
      if (gd[curHash] == 1 &&
          hshs[i][hashes[curHash].second - 1] == hashes[curHash].first &&
          hashes[curHash].second != ptr) {
        ptr = hashes[curHash].second;
        sum++;
      } else {
        ptr++;
        sum++;
      }
    }
    for (int j = 0; j < words[i].size(); j++) {
      gd[hshs[i][j]]++;
      if (hashes[hshs[i][j]] ==
          make_pair(hshs[i].back(), (int)words[i].size())) {
        gd[hshs[i][j]]--;
      }
      hashes[hshs[i][j]] = {hshs[i].back(), words[i].size()};
    }
  }
  cout << sum - 1;
  return 0;
}
