#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  puts("");
}
int a, b, c, d, n;
int x[26];
char mp[105][105];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c >> d >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  if (a % 2 == 0) {
    for (int i = 1; i <= max(b, d); i++)
      for (int j = 1; j <= a + c; j++) mp[i][j] = '.';
    int cur = 1;
    for (int i = 1; i <= a / 2; i++) {
      for (int j = 1; j <= b; j++) {
        mp[j][i * 2 - 1] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
      for (int j = b; j >= 1; j--) {
        mp[j][i * 2] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
    for (int i = 1; i <= c / 2; i++) {
      for (int j = 1; j <= d; j++) {
        mp[j][a + i * 2 - 1] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
      for (int j = d; j >= 1; j--) {
        mp[j][a + i * 2] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
    if (c % 2) {
      for (int j = 1; j <= d; j++) {
        mp[j][a + c] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
  } else {
    for (int i = 1; i <= max(b, d); i++)
      for (int j = 1; j <= a + c; j++) mp[i][j] = '.';
    int cur = 1;
    for (int i = b; i >= 1; i--) {
      mp[i][1] = cur + 'a' - 1;
      x[cur]--;
      if (x[cur] == 0) cur++;
    }
    for (int i = 1; i <= a / 2; i++) {
      for (int j = 1; j <= b; j++) {
        mp[j][i * 2] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
      for (int j = b; j >= 1; j--) {
        mp[j][i * 2 + 1] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
    for (int i = 1; i <= c / 2; i++) {
      for (int j = 1; j <= d; j++) {
        mp[j][a + i * 2 - 1] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
      for (int j = d; j >= 1; j--) {
        mp[j][a + i * 2] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
    if (c % 2) {
      for (int j = 1; j <= d; j++) {
        mp[j][a + c] = cur + 'a' - 1;
        x[cur]--;
        if (x[cur] == 0) cur++;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= max(b, d); i++) {
    for (int j = 1; j <= a + c; j++) cout << mp[i][j];
    cout << endl;
  }
  return 0;
}
