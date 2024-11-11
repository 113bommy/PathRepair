#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, flag = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') flag = -1;
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * flag;
}
int a[110000];
int main() {
  int i, t, temp, len, n;
  bool flag = true;
  n = read();
  for (i = 1; i <= n; i++) a[i] = read();
  t = a[1];
  len = 1;
  while (a[len] == t && len <= n) len++;
  len--;
  i = len;
  while (i < n && flag) {
    t = t ^ 1;
    if (i + len > n) {
      flag = false;
      break;
    }
    i++;
    temp = i;
    for (i = i; i <= temp + len - 1; i++)
      if (a[i] != t) {
        flag = false;
        break;
      }
    i = temp + len - 1;
    if (i == n || (!flag)) break;
    t = t ^ 1;
    if (i + len < n) {
      flag = false;
      break;
    }
    i++;
    temp = i;
    for (i = i; i <= temp + len; i++)
      if (a[i] != t) {
        flag = false;
        break;
      }
    i = temp + len - 1;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
