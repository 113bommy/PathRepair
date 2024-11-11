#include <bits/stdc++.h>
inline int scan() {
  int x = 0, f = 1;
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
inline void Out(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
using namespace std;
const int maxn = 100005;
char maps[2][1004];
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 2; i++) {
    cin >> maps[i];
  }
  int len = strlen(maps[0]);
  int ans = 0;
  for (int i = 0; i < len; i++) {
    int temp = 0;
    if (maps[0][i] == '0') temp++;
    if (maps[0][i + 1] == '0') temp++;
    if (maps[1][i] == '0') temp++;
    if (maps[1][i + 1] == '0') temp++;
    if (temp == 4) {
      if (maps[0][i + 2] == '0' && maps[1][i + 1] == '0') {
        ans += 2, i += 2;
        continue;
      }
    }
    if (temp >= 3) ans++, i++;
  }
  cout << ans << endl;
  return 0;
}
