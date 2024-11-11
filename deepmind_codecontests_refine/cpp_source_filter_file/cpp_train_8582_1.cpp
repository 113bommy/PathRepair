#include <bits/stdc++.h>
using namespace std;
int k[6];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s1, s2, s3, s4, s5, s6;
  if (n == 8) {
    cout << "vaporeon" << endl;
    return 0;
  }
  if (n == 6) {
    cout << "espeon" << endl;
    return 0;
  }
  s1 = "jolt";
  s2 = "flar";
  s3 = "umbr";
  s4 = "leaf";
  s5 = "glac";
  s6 = "sylv";
  for (int i = 0; i < n - 3; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      if (s[i] == s1[i]) k[1]++;
      if (s[i] == s2[i]) k[2]++;
      if (s[i] == s3[i]) k[3]++;
      if (s[i] == s4[i]) k[4]++;
      if (s[i] == s5[i]) k[5]++;
      if (s[i] == s6[i]) k[6]++;
    }
  }
  int max = -1;
  int ans = 0;
  for (int i = 1; i <= 6; i++) {
    if (k[i] > max) {
      max = k[i];
      ans = i;
    }
  }
  if (ans == 1) {
    cout << s1 + "eon" << endl;
    return 0;
  }
  if (ans == 2) {
    cout << s2 + "eon" << endl;
    return 0;
  }
  if (ans == 3) {
    cout << s3 + "eon" << endl;
    return 0;
  }
  if (ans == 4) {
    cout << s4 + "eon" << endl;
    return 0;
  }
  if (ans == 5) {
    cout << s5 + "eon" << endl;
    return 0;
  }
  if (ans == 6) {
    cout << s6 + "eon" << endl;
    return 0;
  }
  return 0;
}
