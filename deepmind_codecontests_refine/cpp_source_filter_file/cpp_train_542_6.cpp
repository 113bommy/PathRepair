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
const int _ = 200007, inf = 0x3f3f3f3f;
int n, qn, val[_] = {0};
int r3[_] = {0};
vector<int> ans3[_];
void make3p() {
  static int stk[_], ll[_], rr[_];
  int top = 0;
  val[0] = val[n + 1] = -inf;
  stk[++top] = 0;
  for (int i = 1; i <= n; i++) {
    while (val[stk[top]] >= val[i]) top--;
    ll[i] = stk[top], stk[++top] = i;
  }
  top = 0, stk[++top] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (val[stk[top]] >= val[i]) top--;
    rr[i] = stk[top], stk[++top] = i;
  }
  for (int i = 1; i <= n; i++)
    if (ll[i] >= 1 && rr[i] <= n)
      if (rr[i] < r3[ll[i]])
        r3[ll[i]] = rr[i], ans3[ll[i]] = vector<int>{ll[i], i, rr[i]};
}
void make3() {
  for (int i = 1; i <= n + 1; i++) r3[i] = n + 1;
  make3p();
  for (int i = 1; i <= n; i++) val[i] = inf - val[i];
  make3p();
  for (int i = 1; i <= n; i++) val[i] = inf - val[i];
  for (int i = n; i >= 1; i--)
    if (r3[i + 1] < r3[i]) r3[i] = r3[i + i], ans3[i] = ans3[i + 1];
}
int bound(int que[], int r, int tar) {
  int l = 1, ans = 0;
  while (r >= l) {
    int mid = (l + r) >> 1;
    if (que[mid] <= tar)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return que[ans];
}
int r4[_] = {0};
vector<int> ans4[_];
void make4() {
  for (int i = 1; i <= n + 1; i++) r4[i] = n + 1;
  static int stk1[_], stk2[_], cnts[_];
  static vector<int> hav[_];
  set<int> s;
  int top1 = 0, top2 = 0;
  memset(cnts, 0, sizeof(cnts));
  for (int i = n; i >= 1; i--) {
    while (top1 && val[stk1[top1]] < val[i]) {
      if (++cnts[stk1[top1]] == 2) hav[i].emplace_back(stk1[top1]);
      top1--;
    }
    while (top2 && val[stk2[top2]] > val[i]) {
      if (++cnts[stk2[top2]] == 2) hav[i].emplace_back(stk2[top2]);
      top2--;
    }
    stk1[++top1] = i, stk2[++top2] = i;
  }
  top1 = top2 = 0;
  for (int i = n; i >= 1; i--) {
    while (top1 && val[stk1[top1]] <= val[i]) top1--;
    while (top2 && val[stk2[top2]] >= val[i]) top2--;
    stk1[++top1] = i, stk2[++top2] = i;
    for (auto a : hav[i]) s.emplace(a);
    if (top1 == 1 || top2 == 1) continue;
    auto loc = s.lower_bound(max(stk1[top1 - 1], stk2[top2 - 1]));
    if (loc == s.end()) continue;
    int vals = *loc, p1 = bound(stk1, top1, vals), p2 = bound(stk2, top2, vals);
    if (p1 > p2) swap(p1, p2);
    if (vals < r4[i]) r4[i] = vals, ans4[i] = vector<int>{i, p1, p2, vals};
  }
  for (int i = n; i >= 1; i--)
    if (r4[i + 1] < r4[i]) r4[i] = r4[i + 1], ans4[i] = ans4[i + 1];
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), qn = ty();
  for (int i = 1; i <= n; i++) val[i] = ty();
  make3(), make4();
  for (int qq = 1; qq <= qn; qq++) {
    int l = ty(), r = ty();
    if (r >= r4[l]) {
      cout << 4 << lf;
      for (auto i : ans4[l]) cout << i << ' ';
      cout << lf;
    } else if (r >= r3[l]) {
      cout << 3 << lf;
      for (auto i : ans3[l]) cout << i << ' ';
      cout << lf;
    } else
      cout << 0 << lf;
  }
  return 0;
}
