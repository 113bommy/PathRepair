#include <bits/stdc++.h>
using namespace std;
int m;
char str[100010];
char _str[100010];
int _cnt[26];
int len;
bool cnt;
bool C(int k) {
  int cnt = 1;
  for (int i = 0; i < len; i++) {
    if (str[i] - 'a' < k)
      cnt = 1;
    else
      cnt++;
    if (cnt > m) return false;
  }
  return true;
}
int solve(int k) {
  int res = 0;
  int cnt = 1, last = -1;
  for (int i = 0; i < len; i++) {
    if (str[i] - 'a' < k)
      cnt = 1;
    else
      cnt++;
    if (str[i] - 'a' == k) last = i;
    if (cnt > m) {
      cnt = i - last;
      res++;
      cnt = max(1, cnt);
    }
  }
  return res;
}
int main() {
  scanf("%d", &m);
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    _cnt[str[i] - 'a']++;
  }
  int l = 0, r = 26;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (C(m))
      r = m;
    else
      l = m;
  }
  int ans = solve(l);
  if (m >= len) {
    for (int i = 0; i < 26; i++)
      if (_cnt[i] > 0) {
        printf("%c", i + 'a');
        break;
      }
  } else {
    _cnt[l] = ans;
    for (int i = 0; i <= l; i++) {
      while (_cnt[i] > 0) {
        _cnt[i]--;
        printf("%c", i + 'a');
      }
    }
  }
  printf("\n");
}
