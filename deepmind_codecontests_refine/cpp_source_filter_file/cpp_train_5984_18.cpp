#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long ans = 0;
  for (char i = 'a'; i <= 'z'; ++i) {
    long long cnt = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (i == s[j]) ++cnt;
    }
    ans += (cnt * cnt);
  }
  for (char i = '0'; i <= '9'; ++i) {
    long long cnt = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (i == s[j]) ++cnt;
    }
    ans += (cnt * cnt);
  }
  printf("%d", ans);
  return 0;
}
