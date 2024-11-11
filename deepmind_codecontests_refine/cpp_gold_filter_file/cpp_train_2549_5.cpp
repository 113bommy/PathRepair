#include <bits/stdc++.h>
using namespace std;
int t[30];
int f1(char* str, int len, int s) {
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] != s) cnt++;
  }
  return cnt;
}
int main() {
  char str[30];
  gets(str);
  int len = strlen(str);
  memset(t, 0, sizeof(t));
  for (int i = 0; i < len; ++i) {
    t[str[i] - 'a']++;
  }
  int cnt = 0;
  for (int i = 0; i < 30; ++i) {
    if (t[i] > 0) cnt++;
  }
  int res = (len + 1) * (26 - cnt);
  for (int i = 0; i < 26; ++i) {
    if (t[i] >= 1) {
      res += f1(str, len, 'a' + i) + 1;
    }
  }
  cout << res << endl;
  return 0;
}
