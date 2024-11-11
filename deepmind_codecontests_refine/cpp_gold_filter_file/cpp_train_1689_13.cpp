#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  string s, s1;
  cin >> a;
  while (a--) {
    bool x = false;
    map<char, int> S;
    map<char, int> S1;
    set<char> A;
    cin >> s >> s1;
    for (int i = 0; i < s.length(); i++) {
      S[s[i]]++;
      A.insert(s[i]);
    }
    for (int i = 0; i < s1.length(); i++) {
      S1.clear();
      for (int l = i; l < i + s.length() && l < s1.length(); l++) {
        S1[s1[l]]++;
      }
      set<char>::iterator it;
      it = A.begin();
      for (it; it != A.end(); it++) {
        if (S[*it] != S1[*it]) {
          x = false;
          break;
        } else {
          x = true;
        }
      }
      if (x) {
        break;
      }
    }
    if (x) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
