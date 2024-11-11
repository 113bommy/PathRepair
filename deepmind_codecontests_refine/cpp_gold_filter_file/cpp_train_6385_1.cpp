#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int res = 0;
  for (int i = 0; i < s[0].size() - 1; i++) {
    int same = 0;
    for (int j = 0; j < n - 1; j++) {
      if (s[j][i] == s[j + 1][i]) same++;
    }
    if (same == n - 1)
      res++;
    else
      break;
  }
  cout << res << '\n';
  return 0;
}
