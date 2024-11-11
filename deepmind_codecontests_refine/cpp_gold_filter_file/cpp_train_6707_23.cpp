#include <bits/stdc++.h>
using namespace std;
int len, res, cnt[26];
char s[105];
int main() {
  cin.getline(s, 105);
  len = strlen(s);
  for (int i = (0); i <= (len - 1); i++) cnt[s[i] - 'a']++;
  res = len;
  res = min(res, cnt['i' - 'a']);
  res = min(res, cnt['t' - 'a']);
  res = min(res, cnt['e' - 'a'] / 3);
  res = min(res, (cnt['n' - 'a'] - 1) / 2);
  printf("%d\n", res);
  return 0;
}
