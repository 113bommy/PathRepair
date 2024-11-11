#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  unsigned long int k, i, c1 = 0, c2 = 0;
  cin >> k;
  vector<char> v;
  for (i = 0; i < s.length(); i = i + 1) {
    if (s[i] == '?') {
      c1 = c1 + 1;
    } else if (s[i] == '*') {
      c2 = c2 + 1;
    }
  }
  unsigned long int minm = s.length() - 2 * c1 - 2 * c2;
  if (k < minm) {
    cout << "Impossible" << endl;
  } else {
    unsigned long int add = k - minm;
    for (i = 0; i < s.length(); i = i + 1) {
      if (s[i + 1] == '?') {
        if (add > 0) {
          v.push_back(s[i]);
          add--;
        }
        i++;
      } else if (s[i + 1] == '*') {
        while (add > 0) {
          v.push_back(s[i]);
          add--;
        }
        i++;
      } else {
        v.push_back(s[i]);
      }
    }
    if (v.size() != k) {
      cout << "Impossible" << endl;
      return 0;
    }
    for (i = 0; i < v.size(); i = i + 1) {
      cout << v[i];
    }
    cout << endl;
  }
}
