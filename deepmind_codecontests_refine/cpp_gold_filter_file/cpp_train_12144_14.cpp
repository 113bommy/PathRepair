#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  map<char, vector<int>> ind;
  for (int i = 0; i < len; i++) {
    if (!ind.count(s[i])) ind[s[i]] = vector<int>();
    ind[s[i]].push_back(i);
  }
  int sum = 0;
  for (auto& it : ind) {
    int best = 0;
    for (int i = 0; i < len; i++) {
      set<char> unique, invalid;
      for (int j : it.second) {
        char c = s[(j + i) % len];
        if (!invalid.count(c)) {
          if (unique.count(c)) {
            unique.erase(c);
            invalid.insert(c);
          } else
            unique.insert(c);
        }
      }
      best = max(best, (int)unique.size());
    }
    sum += best;
  }
  cout << sum / (double)len << endl;
}
