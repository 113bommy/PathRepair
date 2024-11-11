#include <bits/stdc++.h>
using namespace std;
string s;
int n, i, j, k, ans = -1;
int main() {
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      for (k = 0; i + k < n && s[i + k] == s[j + k]; k++)
        ;
      ans = max(ans, k);
    }
  cout << ans;
}
