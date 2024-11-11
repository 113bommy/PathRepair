#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const long long mod = 1e9 + 7;
const int MAXN = 200010;
int n, m, k;
char s[MAXN];
struct Hash {
  long long H[MAXN], B[MAXN];
  long long TH[10][MAXN];
  void init(char *s, int P, int len) {
    H[0] = 0;
    B[0] = 1;
    for (int i = 1; i <= len; ++i) {
      B[i] = B[i - 1] * P % mod;
      H[i] = (H[i - 1] * P + s[i] - '0') % mod;
    }
    for (int v = 0; v < 10; ++v) {
      TH[v][0] = 0;
      for (int i = 1; i <= len; ++i) {
        TH[v][i] = (TH[v][i - 1] * P % mod + v) % mod;
      }
    }
  }
  inline long long get(int l, int r) {
    return ((H[r] - H[l - 1] * B[r - l + 1]) % mod + mod) % mod;
  }
  inline long long get_fixed(int num, int len) { return TH[num][len]; }
} H;
long long t[MAXN << 2];
int tag[MAXN << 2], L[MAXN << 2], R[MAXN << 2];
void Build(int p, int l, int r) {
  t[p] = H.get(l, r);
  tag[p] = -1;
  L[p] = l;
  R[p] = r;
  if (l == r) return;
  int mid = ((l) + ((r) - (l)) / 2);
  Build(p << 1, l, mid);
  Build(p << 1 | 1, mid + 1, r);
}
inline void Push_down(int p) {
  if (tag[p] != -1) {
    tag[p << 1] = tag[p << 1 | 1] = tag[p];
    t[p << 1] = H.get_fixed(tag[p << 1], R[p << 1] - L[p << 1] + 1);
    t[p << 1 | 1] =
        H.get_fixed(tag[p << 1 | 1], R[p << 1 | 1] - L[p << 1 | 1] + 1);
    tag[p] = -1;
  }
}
inline void Push_up(int p) {
  int len_r = R[p << 1 | 1] - L[p << 1 | 1] + 1;
  t[p] = (t[p << 1] * H.B[len_r] % mod + t[p << 1 | 1]) % mod;
}
void Update(int a, int b, int c, int p, int l, int r) {
  if (a <= l && r <= b) {
    t[p] = H.get_fixed(c, r - l + 1);
    tag[p] = c;
    return;
  }
  Push_down(p);
  int mid = ((l) + ((r) - (l)) / 2);
  if (a <= mid) Update(a, b, c, p << 1, l, mid);
  if (b > mid) Update(a, b, c, p << 1 | 1, mid + 1, r);
  Push_up(p);
}
long long Query(int a, int b, int p, int l, int r) {
  if (a <= l && r <= b) {
    return t[p];
  }
  Push_down(p);
  int mid = ((l) + ((r) - (l)) / 2);
  long long res = 0, L, R;
  if (a <= mid) {
    res = Query(a, b, p << 1, l, mid);
  }
  if (b > mid) {
    R = Query(a, b, p << 1 | 1, mid + 1, r);
    if (a <= mid) {
      res = (res * H.B[min(r, b) - mid] % mod + R) % mod;
    } else
      res = R;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  H.init(s, 10, len);
  Build(1, 1, len);
  for (int i = 1; i <= m + k; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a == 1) {
      Update(b, c, d, 1, 1, len);
    } else {
      if (d == c - b + 1)
        printf("YES\n");
      else if (Query(b, c - d, 1, 1, len) == Query(b + d, c, 1, 1, len))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
