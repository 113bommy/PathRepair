#include <bits/stdc++.h>
using namespace std;
const int len = 6e5 + 10;
const int mod = 1e9 + 7;
char str[len];
char ans[len];
int main() {
  int n, k;
  cin >> n >> k;
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++i) str[i + 2 * n] = str[i + n] = str[i];
  int flag = 0;
  for (int i = 1; i < n * 2; ++i) {
    if (str[i] == str[i + 1]) {
      flag = i;
      break;
    }
  }
  if (!flag) {
    if (k % 2)
      for (int i = 1; i <= n; ++i)
        if (str[i] == 'W')
          putchar('B');
        else
          putchar('W');
    else
      for (int i = 1; i <= n; ++i) putchar(str[i]);
  } else {
    for (int i = flag; i <= flag + n; ++i) {
      while (i <= flag + n && str[i] == str[i + 1]) i++;
      int t = i;
      while (t <= flag + n && str[t] != str[t + 1]) t++;
      int num = t - i - 1;
      int l = i + 1, r = t - 1;
      int g = min((num + 1) / 2, k);
      if (str[i] == str[t])
        while (g--) str[l++] = str[r--] = str[i];
      else
        while (g--) str[l++] = str[i], str[r--] = str[t];
      while (l <= r) {
        if (str[l - 1] == 'W')
          str[l++] = 'B';
        else
          str[l++] = 'W';
        if (str[r + 1] == 'W')
          str[r--] = 'B';
        else
          str[r--] = 'W';
      }
      i = t;
    }
    for (int i = flag; i <= flag + n; ++i) ans[i % n] = str[i];
    for (int i = 1; i < n; ++i) putchar(ans[i]);
    putchar(ans[0]);
  }
}
