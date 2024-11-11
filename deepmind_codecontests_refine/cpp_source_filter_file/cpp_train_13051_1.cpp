#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
int l, r, p, tot, cnt, ans;
int prime[10001], used[5000001], num[5000001], res[5000001];
inline char nc() {
  char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(int &x) {
  char c = getchar();
  int b = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar())
    ;
  x = x * b;
}
inline void read(long long &x) {
  char c = getchar();
  int b = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar())
    ;
  x = x * b;
}
void solve(int x, int y) {
  num[++cnt] = x;
  for (int i = (y); i <= (tot); i++)
    if (x * prime[i] > r)
      return;
    else
      solve(x * prime[i], i);
}
int main(int argc, char *argv[]) {
  read(l);
  read(r);
  read(p);
  for (int i = (2); i <= (p - 1); i++) {
    if (!used[i]) prime[++tot] = i;
    for (int j = (1); j <= (tot); j++) {
      if (i * prime[j] >= p) break;
      used[i * prime[j]] = 1;
      if (!(i % prime[j])) break;
    }
  }
  solve(1, 1);
  for (int i = (1); i <= (cnt); i++) res[i] = inf, used[i] = 0;
  res[1] = 0;
  sort(num + 1, num + cnt + 1);
  for (int i = (2); i <= (p - 1); i++) {
    int k = 1;
    for (int j = (1); j <= (cnt); j++) {
      if (num[j] % i != 0) continue;
      while (num[k] * i < num[j]) k++;
      res[j] = ((res[j]) < (res[k] + 1) ? (res[j]) : (res[k] + 1));
      if (res[j] + i <= p) used[j] = 1;
    }
  }
  for (int i = (1); i <= (cnt); i++)
    if (used[i] && num[i] >= l) ans++;
  printf("%d\n", ans);
  return 0;
}
