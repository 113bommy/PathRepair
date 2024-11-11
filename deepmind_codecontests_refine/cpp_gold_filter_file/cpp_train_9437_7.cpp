#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  set<char> A;
  vector<int> cnt(26);
  for (char c : s) {
    A.insert(c);
    cnt[c - 'a']++;
  }
  if (A.size() == 4) {
    cout << "Yes" << endl;
  } else if (A.size() == 2) {
    bool ok = true;
    for (char c : A) {
      if (cnt[c - 'a'] < 2) ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  } else if (A.size() == 3) {
    int ok = 0;
    for (char c : A) {
      if (cnt[c - 'a'] >= 2) ok++;
    }
    if (ok >= 1) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  } else
    cout << "No" << endl;
}
