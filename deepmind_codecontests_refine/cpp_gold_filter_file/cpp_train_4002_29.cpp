#include <bits/stdc++.h>
using namespace std;
string s;
long long n = 1, k = 1, r = 1;
bool ok(char c) {
  if (c >= 'A' && c <= 'Z') return true;
  return false;
}
bool okk(char c) {
  if (c >= 'a' && c <= 'z') return true;
  return false;
}
bool ook(char c) {
  if (c >= '0' && c <= '9') return true;
  return false;
}
int main() {
  cin >> s;
  if (s.size() < 5) {
    cout << "Too weak";
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (ok(s[i])) n = 0;
    if (okk(s[i])) k = 0;
    if (ook(s[i])) r = 0;
  }
  if (r == 1 || n == 1 || k == 1)
    cout << "Too weak";
  else
    cout << "Correct";
  return 0;
}
