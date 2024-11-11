#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  s += '0';
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '0')
      ans++;
    else {
      printf("%d", ans);
      ans = 0;
    }
  }
  return 0;
}
