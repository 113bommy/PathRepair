#include <bits/stdc++.h>
using namespace std;
map<char, int> a;
char s[100010];
int n;
int main() {
  cin >> s;
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    a[s[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[s[i]];
  }
  cout << ans << endl;
  return 0;
}
