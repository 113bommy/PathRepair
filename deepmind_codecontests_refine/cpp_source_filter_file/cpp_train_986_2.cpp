#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool read(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
int X[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[] = {-1, 0, +1, 1, 1, 0, -1, -1};
long long pas[1005][1005];
int main() {
  pas[0][0] = 1;
  for (int i = 1; i <= 10; i++) {
    pas[i][0] = pas[i][i] = 1;
    for (int j = 1; j < i; j++) {
      pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
      pas[i][j] %= 1000000007;
    }
  }
  int n;
  int tot = 0;
  long long ans = 1;
  read(n);
  for (int i = 0; i < n; i++) {
    int a;
    read(a);
    a--;
    ans = (ans * pas[tot + a][a]) % 1000000007;
    a++;
    tot += a;
  }
  cout << ans << endl;
  return 0;
}
