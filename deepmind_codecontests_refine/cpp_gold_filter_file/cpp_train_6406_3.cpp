#include <bits/stdc++.h>
using namespace std;
int main() {
  string word;
  while (cin >> word) {
    vector<pair<bool, bool>> valid(word.size() + 1);
    valid.back() = make_pair(true, true);
    set<string> suffixes;
    for (int i = word.size() - 2; i >= 5; i--) {
      if (valid[i + 2].second ||
          valid[i + 2].first && (i + 2 == word.size() ||
                                 word.substr(i, 2) != word.substr(i + 2, 2))) {
        valid[i].first = true;
        suffixes.insert(word.substr(i, 2));
      }
      if (i + 3 > word.size()) continue;
      if (valid[i + 3].first ||
          valid[i + 3].second && (i + 3 == word.size() ||
                                  word.substr(i, 3) != word.substr(i + 3, 3))) {
        valid[i].second = true;
        suffixes.insert(word.substr(i, 3));
      }
    }
    cout << suffixes.size() << '\n';
    for (string s : suffixes) cout << s << '\n';
  }
}
