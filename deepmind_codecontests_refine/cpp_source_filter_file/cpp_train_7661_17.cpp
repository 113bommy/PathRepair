#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 500007;
struct cxk {
  int a, b, l, r, tr;
  cxk(int a_ = 0, int b_ = 0, int l_ = 0, int r_ = 0, int tr_ = 0) {
    a = a_, b = b_, l = l_, r = r_, tr = tr_;
  }
  friend int operator<(cxk a, cxk b) { return a.l > b.l; }
};
priority_queue<cxk> dlq;
vector<cxk> e[_][2];
int n, m, f[_][2];
void make(int a, int b, int l, int r) {
  int dir = l & 1;
  if (f[a][dir] >= l) {
    if (b == n) {
      cout << l + 1 << lf;
      exit(0);
    }
    if (f[b][dir ^ 1] < r + 1) {
      f[b][dir ^ 1] = r + 1;
      for (auto i : e[b][!dir]) dlq.emplace(i.a, i.b, i.l + 1, i.r, 0);
      e[b][!dir].clear();
    }
  } else
    e[a][dir].emplace_back(a, b, l, r, 0);
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  if (n == 1) {
    cout << 0 << lf;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int a = ty(), b = ty(), l = ty(), r = ty() - 1, dir = (r - l) & 1;
    dlq.emplace(a, b, l, r - dir, 1);
    dlq.emplace(a, b, l + 1, r + dir - 1, 1);
  }
  memset(f, -64, sizeof(f)), f[1][0] = 0;
  while (!dlq.empty()) {
    cxk a = dlq.top();
    dlq.pop();
    if (a.l > a.r) continue;
    make(a.a, a.b, a.l, a.r);
    if (a.tr) make(a.b, a.a, a.l, a.r);
  }
  cout << -1 << lf;
  return 0;
}
