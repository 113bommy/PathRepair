#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    int t = 0;
    string p;
    cin >> p;
    for (int j = 0; j < p.size(); j++) {
      t = t | (1 << (p[j] - 97));
    }
    vector<int> l;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] & t) {
        t = t | s[j];
      } else {
        l.push_back(s[j]);
      }
    }
    l.push_back(t);
    s = l;
  }
  cout << s.size();
  return 0;
}
