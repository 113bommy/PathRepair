#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> vs[5];
int solve(string s1, string s2) {
  int n = s1.size(), m = s2.size();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  for (int i = 0; i < min(n, m); i++) {
    if (s1[i] == '0' || s2[i] == '0')
      continue;
    else
      return 0;
  }
  return 1;
}
int main() {
  cin >> n;
  int weiss = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "0")
      weiss = 1;
    else
      vs[s.size()].push_back(s);
  }
  for (auto s3 : vs[3])
    for (auto s2 : vs[2])
      for (auto s1 : vs[1])
        if (solve(s3, s2) and solve(s2, s1) and solve(s3, s1)) {
          if (weiss) {
            cout << 4 << endl;
            cout << s3 << " " << s2 << " " << s1 << " "
                 << "0" << endl;
          } else {
            cout << 3 << endl;
            cout << s3 << " " << s2 << " " << s1 << endl;
          }
          return 0;
        }
  for (auto s3 : vs[3])
    for (auto s2 : vs[2])
      if (solve(s3, s2)) {
        if (weiss) {
          cout << 3 << endl;
          cout << s3 << " " << s2 << " "
               << "0" << endl;
        } else {
          cout << 2 << endl;
          cout << s3 << " " << s2 << endl;
        }
        return 0;
      }
  for (auto s3 : vs[3])
    for (auto s1 : vs[1])
      if (solve(s3, s1)) {
        if (weiss) {
          cout << 2 << endl;
          cout << s3 << " " << s1 << " "
               << "0" << endl;
        } else {
          cout << 2 << endl;
          cout << s3 << " " << s1 << endl;
        }
        return 0;
      }
  for (auto s2 : vs[2])
    for (auto s1 : vs[1])
      if (solve(s1, s2)) {
        if (weiss) {
          cout << 2 << endl;
          cout << s2 << " " << s1 << " "
               << "0" << endl;
        } else {
          cout << 2 << endl;
          cout << s2 << " " << s1 << endl;
        }
        return 0;
      }
  if (vs[3].empty() and vs[2].empty() and vs[1].empty() and weiss) {
    cout << 1 << endl;
    cout << "0" << endl;
    return 0;
  }
  cout << 1 + weiss << endl;
  if (weiss) cout << "0 ";
  for (auto s3 : vs[3]) {
    cout << s3 << endl;
    return 0;
  }
  for (auto s2 : vs[2]) {
    cout << s2 << endl;
    return 0;
  }
  for (auto s1 : vs[1]) {
    cout << s1 << endl;
    return 0;
  }
  return 0;
}
