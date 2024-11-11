#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char s[2002];
  cin >> s;
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--) {
    s[2 * len - 1 - i] = s[i];
  }
  cout << s << '\n';
  return 0;
}
