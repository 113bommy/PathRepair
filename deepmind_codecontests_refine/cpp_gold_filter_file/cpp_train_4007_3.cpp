#include <bits/stdc++.h>
using namespace std;
int read() {
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
int n, m, K, mp[1005][1005];
int main() {
  memset(mp, 0, sizeof(mp));
  n = read();
  m = read();
  K = read();
  for (int i = 1; i <= K; i++) {
    int x = read(), y = read();
    mp[x][y] = 1;
    if (mp[x + 1][y] && mp[x][y + 1] && mp[x + 1][y + 1]) {
      cout << i << endl;
      return 0;
    }
    if (mp[x + 1][y] && mp[x][y - 1] && mp[x + 1][y - 1]) {
      cout << i << endl;
      return 0;
    }
    if (mp[x - 1][y] && mp[x][y + 1] && mp[x - 1][y + 1]) {
      cout << i << endl;
      return 0;
    }
    if (mp[x - 1][y] && mp[x][y - 1] && mp[x - 1][y - 1]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
