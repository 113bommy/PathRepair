#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
template <typename T1, typename T2>
inline bool Min(T1 &a, const T2 &b) {
  if (b >= a) return false;
  a = b;
  return true;
}
template <typename T1, typename T2>
inline bool Max(T1 &a, const T2 &b) {
  if (b <= a) return false;
  a = b;
  return true;
}
template <typename T1, typename T2>
inline void Mad(T1 &a, const T2 &b) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
const int N = 2e5 + 10;
int n, q;
char s[N];
int a[N];
struct tree {
  int l, r;
  int a, b, ab, bc, abc, lzy;
  void Modify(int v) {
    a += v, b += v;
    ab -= v, bc -= v;
    lzy += v;
  }
} tre[N * 4];
void PushUp(int x) {
  tre[x].a = max(tre[x << 1].a, tre[x << 1 | 1].a);
  tre[x].b = min(tre[x << 1].b, tre[x << 1 | 1].b);
  tre[x].ab = max({tre[x << 1].ab, tre[x << 1 | 1].ab,
                   tre[x << 1].a - 2 * tre[x << 1 | 1].b});
  tre[x].bc = max({tre[x << 1].bc, tre[x << 1 | 1].bc,
                   tre[x << 1 | 1].a - 2 * tre[x << 1].b});
  tre[x].abc = max({tre[x << 1].abc, tre[x << 1 | 1].abc,
                    tre[x << 1].ab + tre[x << 1 | 1].a,
                    tre[x << 1].a + tre[x << 1 | 1].bc});
}
void PushDown(int x) {
  if (tre[x].lzy) {
    tre[x << 1].Modify(tre[x].lzy), tre[x << 1 | 1].Modify(tre[x].lzy);
    tre[x].lzy = 0;
  }
}
void Build(int x, int l, int r) {
  tre[x].l = l, tre[x].r = r, tre[x].lzy = 0;
  if (l == r) {
    tre[x].Modify(a[l]);
    return;
  }
  int m = l + r >> 1;
  Build(x << 1, l, m);
  Build(x << 1 | 1, m + 1, r);
  PushUp(x);
}
void Update(int x, int pl, int pr, int v) {
  int l = tre[x].l, r = tre[x].r;
  if (pl <= l && r <= pr) {
    tre[x].Modify(v);
    return;
  }
  PushDown(x);
  int m = l + r >> 1;
  if (pl <= m) Update(x << 1, pl, pr, v);
  if (pr > m) Update(x << 1 | 1, pl, pr, v);
  PushUp(x);
}
int main() {
  cin >> n >> q;
  n = (n - 1) * 2;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
  Build(1, 1, n);
  printf("%d\n", tre[1].abc);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l > r) swap(l, r);
    if (s[l] != s[r]) {
      Update(1, l, r - 1, s[l] == '(' ? -2 : 2);
      swap(s[l], s[r]);
    }
    printf("%d\n", tre[1].abc);
  }
  return 0;
}
