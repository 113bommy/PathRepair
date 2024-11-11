#include <bits/stdc++.h>
using namespace std;
string s;
int t;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    vector<int> v[3];
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') v[0].push_back(i);
      if (s[i] >= 'a' && s[i] <= 'z') v[1].push_back(i);
      if (s[i] >= '0' && s[i] <= '9') v[2].push_back(i);
    }
    vector<int> no;
    for (int i = 0; i < 3; i++) {
      if (!v[i].size()) no.push_back(i);
    }
    if (!no.size()) {
      cout << s << endl;
      continue;
    } else if (no.size() == 1) {
      if (no.back() == 0) {
        if (v[1].size() > 1) {
          s[v[1].back()] = 'A';
        } else if (v[2].size() > 1) {
          s[v[2].back()] = 'A';
        }
      }
      if (no.back() == 1) {
        if (v[0].size() > 1) {
          s[v[0].back()] = 'a';
        } else if (v[2].size() > 1) {
          s[v[2].back()] = 'a';
        }
      }
      if (no.back() == 2) {
        if (v[0].size() > 1) {
          s[v[0].back()] = '1';
        } else if (v[1].size() > 1) {
          s[v[1].back()] = '1';
        }
      }
    } else {
      if (no[0] + no[1] == 1) {
        s[0] = 'A';
        s[1] = 'a';
      } else if (no[0] + no[1] == 2) {
        s[1] = 'A';
        s[0] = '2';
      } else {
        s[0] = 'a';
        s[1] = 'A';
      }
    }
    cout << s << endl;
  }
}
