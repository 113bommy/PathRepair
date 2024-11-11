#include <bits/stdc++.h>
using namespace std;
const int M = 10000 + 10;
int main() {
  int n, k;
  cin >> n >> k;
  set<int> res;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    string s[4];
    for (int j = 0; j < 4; j++) {
      cin >> s[j];
    }
    string t[4];
    for (int j = 0; j < 4; j++) {
      int len = s[j].length();
      string tmp = "";
      int num_vowel = 0;
      int index = -1;
      for (int ii = len - 1; ii >= 0; ii--) {
        if (s[j][ii] == 'a' || s[j][ii] == 'e' || s[j][ii] == 'i' ||
            s[j][ii] == 'o' || s[j][ii] == 'u') {
          num_vowel++;
          if (num_vowel == k) {
            index = ii;
          }
        }
      }
      if (num_vowel >= k) {
        for (int ii = index; ii < len; ii++) {
          tmp = tmp + s[j][ii];
        }
      }
      t[j] = tmp;
    }
    if (t[0] != "" && t[1] != "" && t[2] != "" && t[3] != "") {
      if (t[0] == t[1] && t[1] == t[2] && t[2] == t[3]) {
        res.insert(4);
      } else {
        if (t[0] == t[1] && t[2] == t[3]) {
          res.insert(1);
        } else {
          if (t[0] == t[2] && t[1] == t[3]) {
            res.insert(2);
          } else {
            if (t[0] == t[3] && t[1] == t[2]) {
              res.insert(3);
            } else {
              flag = false;
            }
          }
        }
      }
    } else {
      flag = false;
    }
  }
  if (res.size() > 2 || (res.size() == 2 && res.find(4) == res.end()) ||
      res.size() == 0 || flag == false) {
    cout << "NO" << endl;
  } else {
    set<int>::iterator it = res.begin();
    int t = (*it);
    if (t == 1) {
      cout << "aabb" << endl;
    }
    if (t == 2) {
      cout << "abab" << endl;
    }
    if (t == 3) {
      cout << "abba" << endl;
    }
    if (t == 4) {
      cout << "aaaa" << endl;
    }
  }
  return 0;
}
