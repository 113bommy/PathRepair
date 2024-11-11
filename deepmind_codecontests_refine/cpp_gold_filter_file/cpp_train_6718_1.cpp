#include <bits/stdc++.h>
using namespace std;
int getint() {
  int res = 0, fh = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return fh * res;
}
string s;
int like[20];
int main() {
  int F = getint(), I = getint(), T = getint();
  for (int i = 1; i <= F; i++) {
    getline(cin, s);
    for (int j = 0; j < I; j++) like[j + 1] += (s[j] == 'Y');
  }
  int ans = 0;
  for (int i = 1; i <= I; i++)
    if (like[i] >= T) ans++;
  printf("%d", ans);
  return 0;
}
