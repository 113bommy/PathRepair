#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
string s;
int main() {
  cin >> s;
  string s2 = s;
  s = s + s2;
  int l = s.size();
  int ans = 1;
  int max_1 = 0;
  for (int i = 0; i < l - 1; i++) {
    if (s[i] != s[i + 1]) {
      ans++;
    } else {
      ans = 1;
    }
    max_1 = max(max_1, ans);
  }
  max_1 = min(max_1, l);
  printf("%d\n", max_1);
  return 0;
}
