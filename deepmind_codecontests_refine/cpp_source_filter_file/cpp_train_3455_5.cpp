#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (s[0] != '0' && s.size() == 1 && k >= 1) {
    s[0] = '0';
    --k;
  } else if (s[0] != '0' && s.size() > 1 && k >= 1) {
    s[0] = '1';
    --k;
  }
  int st = 1;
  while (k >= 1 && st < s.size()) {
    if (s[st] != '0') {
      s[st] = '0';
      --k;
    }
    ++st;
  }
  for (auto& c : s) cout << c;
  return 0;
}
