#include <bits/stdc++.h>
using namespace std;
int ans[1000100], n, m, c[1000100];
vector<int> q[1000100], belong[1000100], line[1000100];
inline int getint() {
  int w = 0, q = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? -w : w;
}
void inc(int x) {
  for (; x < 1000100; x += x & -x) c[x]++;
}
int sum(int x) {
  if (x == 0) return 0;
  int val = 0;
  for (; x > 0; x -= x & -x) val += c[x];
  return val;
}
void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l = getint(), r = getint();
    line[r].push_back(l);
  }
  for (int i = 1; i <= m; i++) {
    ans[i] = n;
    int k = getint(), x = 0;
    for (int j = 1; j <= k; j++) {
      int wz = getint();
      q[wz].push_back(x);
      belong[wz].push_back(i);
      x = wz;
    }
    q[1000000].push_back(x);
    belong[1000000].push_back(i);
  }
}
int main() {
  init();
  for (int i = 1; i <= 1000000; i++) {
    int w = q[i].size();
    for (int j = 0; j < w; j++) {
      ans[belong[i][j]] -= sum(i - 1) - sum(q[i][j]);
    }
    w = line[i].size();
    for (int j = 0; j < w; j++) {
      int x = line[i][j];
      inc(x);
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
