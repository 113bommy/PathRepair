#include <bits/stdc++.h>
using namespace std;
string s[100005];
int k[100005];
int pos[2000005];
char ans[2000005];
int main(void) {
  int n, x;
  cin >> n;
  s[0] = "";
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> x;
      if (s[pos[x]].size() < s[i].size()) {
        pos[x] = i;
      }
    }
  }
  int keep = 0, ki = 0;
  for (int i = 1; i <= 2000000; i++) {
    if (pos[i] != 0) {
      if (ki + s[pos[i]].size() > s[keep].size()) {
        keep = pos[i];
        ki = 0;
      }
    }
    if (keep == 0) {
      ans[i] = '*';
    } else {
      ans[i] = s[keep][ki];
    }
    if (keep) ki++;
    if (ki == s[keep].size()) keep = ki = 0;
  }
  int m = 2000000;
  while (m > 0 && ans[m] == '*') ans[m--] = '\0';
  for (int i = 1; i <= m; i++)
    if (ans[i] == '*') ans[i] = 'a';
  cout << (string)(ans + 1) << endl;
  return 0;
}
