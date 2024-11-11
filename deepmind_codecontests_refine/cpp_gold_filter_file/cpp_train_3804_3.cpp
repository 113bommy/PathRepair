#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int n;
struct Q {
  int type;
  long long time;
  long long val;
  int id;
  int ans;
} a[N];
map<long long, int> m;
inline long long read() {
  char ch = getchar();
  long long v = 0, c = 1;
  while (!isdigit(ch)) {
    if (ch == '-') c = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    v = v * 10 + ch - 48;
    ch = getchar();
  }
  return v * c;
}
inline bool cmp(Q x, Q y) { return x.time < y.time; }
inline bool cmp2(Q x, Q y) { return x.id < y.id; }
inline void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  sort(a + l, a + mid + 1, cmp);
  sort(a + mid + 1, a + r + 1, cmp);
  ;
  int top = l;
  for (int i = mid + 1; i <= r; ++i) {
    while (i <= r && a[i].type != 3) ++i;
    if (i > r) break;
    while (top <= mid && a[top].time <= a[i].time) {
      if (a[top].type == 1)
        m[a[top].val]++;
      else if (a[top].type == 2)
        m[a[top].val]--;
      top++;
    }
    a[i].ans += m[a[i].val];
  }
  m.clear();
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i].type = read();
    a[i].time = read();
    a[i].val = read();
    a[i].id = i;
  }
  solve(1, n);
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n; ++i)
    if (a[i].type == 3) printf("%d\n", a[i].ans);
  return 0;
}
