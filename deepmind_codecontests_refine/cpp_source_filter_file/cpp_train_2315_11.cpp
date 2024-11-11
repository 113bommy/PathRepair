#include <bits/stdc++.h>
using namespace std;
int Num;
const long long inf = 999999999;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string s;
int flag[110000];
int main() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++)
    if (s[i] == '1') flag[i] = 1;
  for (int i = 0; i < n; i++) {
    if (flag[i] == 0) continue;
    int j = i;
    while (flag[j]) j++;
    if (j - i >= 2) {
      flag[i] = -1;
      for (int k = i + 1; k <= j; k++) flag[k] = 0;
      flag[j] = 1;
    }
    i = j - 1;
  }
  int tot = 0;
  for (int i = 0; i <= n; i++)
    if (flag[i] == 1 || flag[i] == -1) tot++;
  printf("%d\n", tot);
  for (int i = 0; i <= n; i++) {
    if (flag[i] == 0) continue;
    if (flag[i] == 1)
      printf("+2^%d\n", i);
    else
      printf("-2^%d\n", i);
  }
}
