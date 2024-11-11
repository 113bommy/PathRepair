#include <bits/stdc++.h>
using namespace std;
bool ok(string s) {
  string s2 = s;
  reverse(s2.begin(), s2.end());
  return s2 == s;
}
string to_string(char c) {
  string ret;
  ret += c;
  return ret;
}
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      string new_s = s.substr(0, i) + to_string(c) + s.substr(i);
      if (ok(new_s)) {
        printf("%s\n", new_s.c_str());
        return 0;
      }
    }
  }
  printf("NA\n");
  return 0;
}
