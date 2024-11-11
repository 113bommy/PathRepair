#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
char s[100003];
int n;
void pr(int len) {
  for (int i = 0; i < len / 2; i++) printf("4");
  for (int i = 0; i < len / 2; i++) printf("7");
  return;
}
void go(int o) {
  if (o == n) return;
  int j;
  if (s[o] == 4 || s[o] == 7)
    go(o + 1);
  else {
    if (s[o] > 7) {
      for (j = o - 1; j >= 0; j--)
        if (s[j] == 4) break;
      if (j == -1) {
        if (n % 2)
          pr(n + 1);
        else
          pr(n + 2);
        exit(0);
      } else {
        s[j] = 7;
        for (int i = j + 1; i < n; i++) s[i] = 4;
      }
    } else if (s[o] > 4) {
      s[o] = 7;
      for (int i = o + 1; i < n; i++) s[i] = 4;
    } else {
      for (int i = o; i < n; i++) s[i] = 4;
    }
  }
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  if (n % 2) {
    pr(n + 1);
    return 0;
  }
  for (int i = 0; i < n; i++) s[i] -= '0';
  go(0);
  int ff = 0, ss = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 4)
      ff++;
    else
      ss++;
  }
  if (ff == ss) {
    for (int i = 0; i < n; i++) printf("%d", s[i]);
    return 0;
  }
  int l = n - 1;
  while (l >= 0 && !(ss <= n / 2 - 1 && ff <= n / 2 + 1 && s[l] == 4)) {
    if (s[l] == 4)
      ff--;
    else
      ss--;
    l--;
  }
  if (l == -1) {
    pr(n + 2);
    return 0;
  } else {
    s[l++] = 7;
    ss++;
    ff--;
    while (ff < n / 2) {
      ff++;
      s[l++] = 4;
    }
    while (l < n) s[l++] = 7;
  }
  for (int i = 0; i < n; i++) printf("%d", s[i]);
}
