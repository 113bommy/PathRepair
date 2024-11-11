#include <bits/stdc++.h>
using namespace std;
inline int Readint() {
  int ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int MAXN = 100100;
int n;
int k;
pair<long long, long long> p[MAXN];
int pos1[MAXN], pos2[MAXN], pos3[MAXN], pos4[MAXN];
int lst[MAXN];
bool cmp1(int a, int b) { return p[a].first < p[b].first; }
bool cmp2(int a, int b) { return p[a].first > p[b].first; }
bool cmp3(int a, int b) { return p[a].second < p[b].second; }
bool cmp4(int a, int b) { return p[a].second > p[b].second; }
long long ans = (1ll << 62);
void init() {
  n = Readint(), k = Readint();
  long long x1, x2, y1, y2;
  for (int i = 1, _END_ = n; i <= _END_; i++) {
    x1 = Readint(), y1 = Readint();
    x2 = Readint(), y2 = Readint();
    p[i].first = x1 + x2;
    p[i].second = y1 + y2;
    pos1[i] = pos2[i] = pos3[i] = pos4[i] = i;
  }
}
void work() {
  int cnt = 0;
  long long x1, x2, y1, y2;
  long long xx, yy;
  int now = 0;
  for (int a = 0, _END_ = k; a <= _END_; a++)
    for (int b = 0, _END_ = k; b <= _END_; b++)
      for (int c = 0, _END_ = k; c <= _END_; c++)
        for (int d = 0, _END_ = k; d <= _END_; d++) {
          now++;
          cnt = 0;
          for (int i = 1, _END_ = a; i <= _END_; i++)
            if (lst[pos1[i]] != now) {
              lst[pos1[i]] = now;
              cnt++;
            }
          for (int i = 1, _END_ = b; i <= _END_; i++)
            if (lst[pos2[i]] != now) {
              lst[pos2[i]] = now;
              cnt++;
            }
          for (int i = 1, _END_ = c; i <= _END_; i++)
            if (lst[pos3[i]] != now) {
              lst[pos3[i]] = now;
              cnt++;
            }
          for (int i = 1, _END_ = d; i <= _END_; i++)
            if (lst[pos4[i]] != now) {
              lst[pos4[i]] = now;
              cnt++;
            }
          if (cnt != k) continue;
          y1 = x1 = -20000000000LL;
          y2 = x2 = 20000000000LL;
          for (int i = 1, _END_ = n; i <= _END_; i++)
            if (lst[i] != now) {
              x1 = max(x1, p[i].first);
              y1 = max(y1, p[i].second);
              x2 = min(x2, p[i].first);
              y2 = min(y2, p[i].second);
            }
          xx = (long long)(x1 - x2);
          yy = (long long)(y1 - y2);
          xx = max(xx, 2ll);
          yy = max(yy, 2ll);
          ans = min(ans, xx * yy);
        }
  printf("%I64d\n", ans / 4);
}
int main() {
  int _ = 0;
  init();
  sort(pos1 + 1, pos1 + 1 + n, cmp1);
  sort(pos2 + 1, pos2 + 1 + n, cmp2);
  sort(pos3 + 1, pos3 + 1 + n, cmp3);
  sort(pos4 + 1, pos4 + 1 + n, cmp4);
  work();
  close();
  return 0;
}
