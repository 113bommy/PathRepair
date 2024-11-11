#include <bits/stdc++.h>
using namespace std;
int con[512] = {0};
char s[300000] = {0}, s1[300000] = {0};
int main() {
  scanf("%s %s", s, s1);
  int n = strlen(s);
  int m = strlen(s1);
  int u = 0, op = 0;
  int r = 'a' - 'A';
  for (int i = 0; i < n; i++) con[s[i]]++;
  for (int i = 0; i < m; i++)
    if (con[s1[i]] > 0) {
      con[s1[i]]--;
      u++;
      s1[i] = '*';
    }
  for (int i = 0; i < m; i++) {
    if (con[s1[i] - 'a' + 'A'] > 0) {
      con[s1[i] - 'a' + 'A']--;
      op++;
      s1[i] = '+';
    } else if (con[s1[i] - 'A' + 'a'] > 0) {
      con[s1[i] - 'A' + 'a']--;
      op++;
      s1[i] = '+';
    }
  }
  cout << u << " " << op;
  return 0;
}
