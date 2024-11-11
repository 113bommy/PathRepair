#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int c[26];
  for (int i = 0; i < s1.size(); i++) {
    c[s1[i]] = s2[i];
  }
  string s3;
  cin >> s3;
  for (int i = 0; i < s3.size(); i++) {
    if (s3[i] < 57)
      cout << s3[i];
    else if (s3[i] < 96)
      cout << char(c[s3[i] + 32] - 32);
    else
      cout << char(c[s3[i]]);
  }
  return 0;
}
