#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_op(_buf), *_ed(_buf);
inline int getint() {
  int _s = 0, _f = 1;
  char _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                             _op == _ed)
                  ? EOF
                  : *_op++);
  while (!('0' <= _ch && _ch <= '9'))
    (_ch == '-') && (_f = -1),
        _ch =
            (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                            _op == _ed)
                 ? EOF
                 : *_op++);
  while (('0' <= _ch && _ch <= '9'))
    _s = _s * 10 + _ch - 48,
    _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                          _op == _ed)
               ? EOF
               : *_op++);
  return _s * _f;
}
const int N = 2e6 + 1, mod = 998244353;
int n, top;
long long int ans, sum;
char st[N];
struct node {
  int x, y;
  long long int val() { return 1ll * x * y; }
} sta[N];
inline void input() { scanf("%d%s", &n, st + 1); }
inline void init() {}
inline void ins(int x, int y) {
  while (top && sta[top].x <= x) sum -= sta[top].val(), y += sta[top--].y;
  if (y) sta[++top] = (node){x, y};
  sum += sta[top].val();
}
inline void work() {
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (st[i] == '0') {
      while (now) ins(now--, 1);
      ins(0, 1);
    } else
      now++, ins(now, 0);
    ans += sum + 1ll * now * (now + 1) / 2;
  }
  cout << ans;
}
int main() {
  input();
  init();
  work();
  return 0;
}
