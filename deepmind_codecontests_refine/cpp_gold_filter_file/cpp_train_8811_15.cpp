#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n, k, f[2][200050], now;
deque<int> q;
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n + 1; i++) f[0][i] = 0x3f3f3f3f;
  while (k--) {
    int l = read(), r = read();
    now ^= 1;
    q.clear();
    memcpy(f[now], f[now ^ 1], sizeof(f[now]));
    for (int j = 0; j <= min(n, r); j++) {
      while (!q.empty() && q.front() < j - r + l) q.pop_front();
      while (!q.empty() && f[now ^ 1][j] <= f[now ^ 1][q.back()]) q.pop_back();
      q.push_back(j);
      f[now][j] = min(f[now][j], f[now ^ 1][q.front()] + 2);
    }
    q.clear();
    for (int j = r; j >= 0; j--) {
      while (!q.empty() && q.front() < l - j) q.pop_front();
      while (!q.empty() && f[now ^ 1][r - j] <= f[now ^ 1][q.back()])
        q.pop_back();
      q.push_back(r - j);
      f[now][j] = min(f[now][j], f[now ^ 1][q.front()] + 1);
    }
  }
  if (f[now][n] == 0x3f3f3f3f)
    puts("Hungry");
  else {
    puts("Full");
    cout << f[now][n] << endl;
  }
  return 0;
}
