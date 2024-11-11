#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5000;
const int mod = 1e9 + 7;
const long long inf = 1e18;
string s;
int main() {
  int n;
  bool f = 0;
  cin >> n;
  cin >> s;
  if (s[0] == '?' || s[n - 1] == '?') {
    f = 1;
  }
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) continue;
    if (s[i] == '?' && s[i + 1] == '?') {
      f = 1;
      continue;
    }
    if (s[i] == s[i + 1]) {
      f = 0;
      break;
    }
    if (s[i] == '?') {
      int l = i, r = i;
      while (s[l] == '?' && s[r] == '?') {
        if (s[l] == '?') {
          l--;
        }
        if (s[r] == '?') {
          r++;
        }
      }
      if (s[l] == s[r]) f = 1;
    }
  }
  if (f)
    puts("Yes");
  else
    puts("No");
}
