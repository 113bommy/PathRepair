#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  string s1 = s, t1 = t;
  sort(s1.begin(), s1.end());
  sort(t1.begin(), t1.end());
  if (s1.size() == t1.size()) {
    if (s1 == t1) {
      cout << "array" << endl;
    } else {
      cout << "need tree" << endl;
    }
  } else if (s1.size() < t1.size()) {
    cout << "need tree" << endl;
  } else {
    int x;
    x = s.find(t);
    if (x != -1) {
      cout << "automaton" << endl;
    } else {
      string temp;
      s1 = s;
      for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
          if (s[j] == t[i]) {
            temp.push_back(s[j]);
            s.erase(s.begin() + j);
            break;
          }
        }
      }
      if (temp == t) {
        int j = 0;
        for (int i = 0; i < s1.size(); i++) {
          if (s1[i] == t[j]) {
            j++;
          }
        }
        if (j == t.size()) {
          cout << "array" << endl;
        } else {
          cout << "both" << endl;
        }
      } else {
        cout << "need tree" << endl;
      }
    }
  }
  return 0;
}
