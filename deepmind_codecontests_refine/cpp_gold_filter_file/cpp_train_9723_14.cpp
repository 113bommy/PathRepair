#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r;
  vector<int> q;
} t[100005 * 40];
int S, T, rt, N, X[100005], Y[100005], f[100005], ll[100005], rr[100005];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void Union(int &p, int L, int R, int x) {
  if (!p) return;
  for (int i : t[p].q)
    X[T] = min(X[T], X[find(i)]), Y[T] = max(Y[T], Y[find(i)]), f[find(i)] = T;
  t[p].q.clear();
  if (L == R) return;
  if (x <= ((L + R) >> 1))
    Union(t[p].l, L, ((L + R) >> 1), x);
  else
    Union(t[p].r, ((L + R) >> 1) + 1, R, x);
}
void Cover(int &p, int L, int R, int l, int r) {
  if (!p) p = ++S;
  if (l <= L && R <= r) {
    t[p].q.push_back(T);
    return;
  }
  if (r <= ((L + R) >> 1))
    Cover(t[p].l, L, ((L + R) >> 1), l, r);
  else if (((L + R) >> 1) < l)
    Cover(t[p].r, ((L + R) >> 1) + 1, R, l, r);
  else
    Cover(t[p].l, L, ((L + R) >> 1), l, ((L + R) >> 1)),
        Cover(t[p].r, ((L + R) >> 1) + 1, R, ((L + R) >> 1) + 1, r);
}
void doit() {
  scanf("%d", &N);
  for (int i = 1, l, r, t; i <= N; i++) {
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      X[++T] = l, Y[T] = r, ll[T] = l, rr[T] = r, f[T] = T;
      Union(rt, -1e9, 1e9, l), Union(rt, -1e9, 1e9, r);
      if (X[T] < Y[T] - 1) Cover(rt, -1e9, 1e9, X[T] + 1, Y[T] - 1);
    } else
      l = find(l), r = find(r),
      puts(l == r || (X[r] < ll[l] && ll[l] < Y[r]) ||
                   (X[r] < rr[l] && rr[l] < Y[r])
               ? "YES"
               : "NO");
  }
}
int main() {
  doit();
  return 0;
}
