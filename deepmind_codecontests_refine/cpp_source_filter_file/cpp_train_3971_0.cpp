#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, a, s, d, f, g, p1 = 0, p2 = 0;
  vector<long long> b;
  string s1, s2, s3, s4;
  cin >> s1 >> s2;
  s4 = "eyuioa";
  if (s1.size() != s2.size()) {
    cout << "No";
    return 0;
  }
  for (i = 0; i < s1.size(); i++) {
    for (j = 0; j < 6; j++) {
      if (s1[i] == s4[j]) {
        p1 = 1;
      }
      if (s2[i] == s4[j]) {
        p2 = 1;
      }
    }
    if (p1 != p2) {
      cout << "No";
      return 0;
    }
    p1 = 0;
    p2 = 0;
  }
  cout << "Yes";
}
