#include <bits/stdc++.h>
using namespace std;
bool isPoli(string s) {
  for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return false;
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  int count = 0;
  string beg = "";
  string end = "";
  int i = 0, j = s.size() - 1;
  for (; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      if (s[i] == s[j - 1] && isPoli(s.substr(i, j - i))) {
        beg += s[j];
        end += s[j];
        --i;
        ++count;
      } else if (s[i + 1] == s[j] && isPoli(s.substr(i + 1, j - i))) {
        beg += s[i];
        end += s[i];
        ++j;
        ++count;
      } else {
        cout << "NA" << endl;
        return 0;
      }
    } else {
      beg += s[i];
      end += s[j];
    }
  }
  if (count > 1) {
    cout << "NA" << endl;
    return 0;
  }
  if (count == 0) {
    if (i == j) {
      beg += s[i];
      end += s[i];
    } else {
      beg += 'a';
    }
  }
  if (count == 1) {
    if (i == j) {
      beg += s[i];
    } else {
    }
  }
  cout << beg;
  for (int i = end.size() - 1; i >= 0; --i) cout << end[i];
  cout << endl;
  return 0;
}
