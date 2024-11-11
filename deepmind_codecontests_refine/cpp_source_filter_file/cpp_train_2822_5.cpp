#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct JiQiRen {
  int x, r, q;
} s[N];
bool cmp1(JiQiRen a, JiQiRen b) {
  if (a.r != b.r) return a.r > b.r;
  if (a.x != b.x) return a.x < b.x;
  return a.q < b.q;
}
bool cmp2(JiQiRen a, JiQiRen b) { return a.q < b.q; }
int n = 0, k = 0;
int tot = 0, val[N], t[N << 2];
long long ans = 0;
int rd() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
int GetVal(int w) {
  int l = 1, r = tot + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (t[mid] <= w)
      l = mid;
    else
      r = mid;
  }
  return l;
}
int lowbit(int x) { return x & (-x); }
void Add(int x, int w) {
  for (; x <= tot; x += lowbit(x)) val[x]++;
}
void Cln(int x) {
  for (; x <= tot; x += lowbit(x)) val[x] = 0;
}
int Ask(int x) {
  x = min(max(0, x), tot);
  int res = 0;
  for (; x; x -= lowbit(x)) res += val[x];
  return res;
}
void Sol(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  Sol(l, mid), Sol(mid + 1, r);
  sort(s + l, s + mid + 1, cmp2);
  sort(s + mid + 1, s + r + 1, cmp2);
  int p1 = l, p2 = l;
  for (int i = mid + 1; i <= r; i++) {
    while (p1 <= mid && s[i].q - s[p1].q > k) Add(GetVal(s[p1].x), -1), p1++;
    while (p2 <= mid && s[p2].q - s[i].q <= k) Add(GetVal(s[p2].x), 1), p2++;
    ans += Ask(GetVal(s[i].x + s[i].r)) - Ask(GetVal(s[i].x - s[i].r - 1));
  }
  for (int i = l; i <= mid; i++) Cln(GetVal(s[i].x));
  sort(s + l, s + r + 1, cmp1);
}
int main() {
  n = rd(), k = rd();
  for (int i = 1; i <= n; i++) {
    s[i].x = rd(), s[i].r = rd(), s[i].q = rd();
    t[++tot] = s[i].x;
    t[++tot] = s[i].x - s[i].r - 1;
    t[++tot] = s[i].x + s[i].r;
  }
  sort(t + 1, t + tot + 1);
  sort(s + 1, s + n + 1, cmp1);
  Sol(1, n);
  printf("%I64d", ans);
  return 0;
}
