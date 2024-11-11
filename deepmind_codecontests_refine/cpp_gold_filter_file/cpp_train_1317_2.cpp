#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, len;
  string s;
  cin >> n >> s;
  int ans = len = s.length();
  for (int i = 1; i <= len; i++) {
    if (i + i > len) break;
    if (s.substr(0, i) == s.substr(i, i)) ans = i + 1 + (len - i * 2);
  }
  printf("%d\n", ans);
}
