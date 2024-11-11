#include <bits/stdc++.h>
using namespace std;
long long n, t;
int solve(int i, string &s) {
  int index = i;
  char minn = s[index];
  for (int j = i; j < s.size(); j++)
    if (s[j] < minn) {
      minn = s[j];
      index = j;
    }
  swap(s[i], s[index]);
  if (i == index) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    string s, b;
    cin >> s >> b;
    if (s < b) {
      cout << s << endl;
      continue;
    }
    for (int i = 0; i < s.size(); i++) {
      if (solve(i, s)) {
        break;
      }
    }
    if (s.size() > b.size() && s.substr(0, b.size()) == b) {
      cout << "---" << endl;
      continue;
    }
    if (s < b) {
      cout << s << endl;
    } else
      cout << "---" << endl;
  }
  return 0;
}
