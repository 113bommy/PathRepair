#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<string, int> tree;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      string subs = s.substr(i, j - i + 1);
      if (tree.find(subs) == tree.end()) {
        tree[subs] = 1;
      } else {
        tree[subs] += 1;
      }
    }
  }
  int l = 0;
  for (map<string, int>::iterator it = tree.begin(); it != tree.end(); ++it) {
    if (it->second >= 2 && it->first.size()) {
      l = it->first.size();
    }
  }
  cout << l << endl;
  return 0;
}
