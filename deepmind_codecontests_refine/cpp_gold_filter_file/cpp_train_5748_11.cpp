#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 200010;
const int INF = 2147483600;
int N, M;
struct data {
  int d, id, pos;
} a[MAXN + 1], q[MAXN + 1];
int A[MAXN + 1], Ans[MAXN + 1];
bool cmpd(data a, data b) {
  if (a.d != b.d) return a.d > b.d;
  return a.pos < b.pos;
}
bool cmpk(data a, data b) { return a.d < b.d; }
inline int lowbit(int x) { return x & (-x); }
int c[MAXN + 1];
inline int Query(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) {
    ans += c[x];
  }
  return ans;
}
inline void Add(int k, int x) {
  for (; k <= N; k += lowbit(k)) c[k] += x;
  return;
}
int main() {
  N = read();
  for (int i = 1; i <= N; i++) {
    a[i].pos = i;
    a[i].d = read();
    A[i] = a[i].d;
  }
  sort(a + 1, a + N + 1, cmpd);
  M = read();
  for (int i = 1; i <= M; i++) {
    q[i].d = read(), q[i].pos = read();
    q[i].id = i;
  }
  sort(q + 1, q + M + 1, cmpk);
  int nw = 0;
  for (int i = 1; i <= N; i++) {
    Add(a[i].pos, 1);
    while (nw < M && q[nw + 1].d == i) {
      int l = 1, r = N, ans = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (Query(mid) < q[nw + 1].pos)
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      Ans[q[nw + 1].id] = ans + 1;
      ++nw;
    }
  }
  for (int i = 1; i <= M; i++) printf("%d\n", A[Ans[i]]);
  return 0;
}
