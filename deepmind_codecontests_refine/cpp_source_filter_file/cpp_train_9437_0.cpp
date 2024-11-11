#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k = 0, sum_k = 0, s1 = 0, s2 = 0;
  string s;
  cin >> s;
  vector<int> let(26, 0);
  if (s.length() < 4) {
    cout << "No" << endl;
    return 0;
  }
  if (s.length() == 4) {
    if (s[3] == s[2] && s[3] == s[1]) {
      cout << "No" << endl;
      return 0;
    }
    if (s[2] == s[1] && s[2] == s[0]) {
      cout << "No" << endl;
      return 0;
    }
    if (s[3] == s[1] && s[3] == s[0]) {
      cout << "No" << endl;
      return 0;
    }
    if (s[3] == s[0] && s[3] == s[2]) {
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') ++let[0];
    if (s[i] == 'b') ++let[1];
    if (s[i] == 'c') ++let[2];
    if (s[i] == 'd') ++let[3];
    if (s[i] == 'e') ++let[4];
    if (s[i] == 'f') ++let[5];
    if (s[i] == 'g') ++let[6];
    if (s[i] == 'h') ++let[7];
    if (s[i] == 'i') ++let[8];
    if (s[i] == 'j') ++let[9];
    if (s[i] == 'k') ++let[10];
    if (s[i] == 'l') ++let[11];
    if (s[i] == 'm') ++let[12];
    if (s[i] == 'n') ++let[13];
    if (s[i] == 'o') ++let[14];
    if (s[i] == 'p') ++let[15];
    if (s[i] == 'q') ++let[16];
    if (s[i] == 'r') ++let[17];
    if (s[i] == 's') ++let[18];
    if (s[i] == 't') ++let[19];
    if (s[i] == 'u') ++let[20];
    if (s[i] == 'v') ++let[21];
    if (s[i] == 'w') ++let[22];
    if (s[i] == 'x') ++let[23];
    if (s[i] == 'y') ++let[24];
    if (s[i] == 'z') ++let[25];
  }
  for (int i = 0; i < 26; ++i)
    if (let[i] > 0) ++sum_k;
  if (sum_k > 4) {
    cout << "No" << endl;
    return 0;
  }
  if (s.length() > 4 && (sum_k == 4 || sum_k == 3)) {
    cout << "Yes" << endl;
    return 0;
  }
  if (s.length() > 4 && sum_k == 1) {
    cout << "No" << endl;
    return 0;
  }
  if (s.length() > 4 && sum_k == 2) {
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[0])
        ++s1;
      else
        ++s2;
    }
    if (s1 > 1 && s2 > 1) {
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
}
