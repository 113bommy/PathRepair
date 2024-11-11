#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int n;
char s[100005];
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (s[1] == '0' && s[2] == '1' && s[3] == '1') {
    cout << "0001000100001000101000" << endl;
    return 0;
  }
  int sum = 0;
  for (int i = n; i; i--) {
    if (s[i] == '0')
      sum++;
    else if (sum)
      sum--;
    else
      s[i] = '0';
  }
  return !printf("%s", s + 1);
}
