#include <bits/stdc++.h>
using namespace std;
int n;
int m, type;
struct nod {
  long long l, r, w;
} S[100010];
int top;
int l, r, mid, ans;
int sea(long long x) {
  l = 1, r = top, ans = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (S[mid].l > x)
      r = mid - 1;
    else if (S[mid].r < x)
      l = mid + 1;
    else {
      ans = mid;
      break;
    }
  }
  return S[ans].l == S[ans].r ? S[ans].w : sea((x - S[ans].l) % S[ans].w + 1);
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &type);
    if (type == 1) {
      long long x, ls = S[top].r + 1;
      scanf("%I64d", &x);
      S[++top] = (nod){ls, ls, x};
    } else if (type == 2) {
      long long x, c, ls = S[top].r + 1;
      scanf("%I64d%I64d", &x, &c);
      if (x == c && c == 1)
        S[++top] = (nod){ls, ls, S[1].w};
      else
        S[++top] = (nod){ls, ls + c * x - 1, x};
    }
  }
  scanf("%d", &n);
  long long j;
  for (int i = 1; i <= n; ++i) scanf("%I64d", &j), printf("%d ", sea(j));
  return 0;
}
