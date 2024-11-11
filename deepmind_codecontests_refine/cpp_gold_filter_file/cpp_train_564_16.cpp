#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int f = 1, k = 0;
  for (int i = 0; i < s.size() && k < t.size(); i++) {
    if (s[i] == t[k]) {
      k++;
    }
  }
  if (k == t.size()) {
    cout << "automaton";
    return 0;
  }
  if (t.size() == s.size()) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) {
      cout << "array";
      return 0;
    }
  } else {
    map<char, int> mpp1, mpp;
    for (int i = 0; i < s.size(); i++) mpp[s[i]]++;
    for (int i = 0; i < t.size(); i++) mpp1[t[i]]++;
    int f = 0;
    for (int i = 0; i < t.size(); i++) {
      if (mpp1[t[i]] > mpp[t[i]]) {
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << "both";
      return 0;
    }
  }
  cout << "need tree" << endl;
}
