#include <bits/stdc++.h>
using namespace std;
inline long long Readll() {
  long long ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int MAXN = 202020;
int n;
int a[MAXN];
int pos[MAXN];
long long ans;
long long sm[MAXN << 2];
long long A[MAXN];
int oc[MAXN << 2];
int mx[MAXN << 2];
int mn[MAXN << 2];
void init() {
  scanf("%d", &n);
  for (int i = (1), _END_ = (n); i <= _END_; i++)
    scanf("%d", &a[i]), pos[a[i]] = i;
}
void pushdown(int p, int l, int r) {
  if (oc[p]) {
    oc[((p) + (p))] = oc[((p) + (p) + 1)] = oc[p];
    mx[((p) + (p))] = mx[((p) + (p) + 1)] = oc[p];
    mn[((p) + (p))] = mn[((p) + (p) + 1)] = oc[p];
    int mid = (l + r) / 2;
    sm[((p) + (p))] = (mid - l + 1) * 1ll * oc[p];
    sm[((p) + (p) + 1)] = (r - mid) * 1ll * oc[p];
    oc[p] = 0;
  }
}
void built(int p, int l, int r) {
  if (l == r) {
    sm[p] = l;
    mx[p] = l;
    return;
  }
  int mid = (l + r) / 2;
  built(((p) + (p)), l, mid);
  built(((p) + (p) + 1), mid + 1, r);
  sm[p] = sm[((p) + (p))] + sm[((p) + (p) + 1)];
  mx[p] = max(mx[((p) + (p))], mx[((p) + (p) + 1)]);
  mn[p] = min(mn[((p) + (p))], mn[((p) + (p) + 1)]);
}
void modify(int p, int l, int r, int ll, int rr, int vl) {
  if (ll > rr) return;
  if (l == r) {
    oc[p] = mn[p] = mx[p] = max(mx[p], vl);
    sm[p] = mx[p];
    return;
  }
  pushdown(p, l, r);
  if (mn[p] > vl) return;
  if (l == ll && r == rr && mx[p] <= vl) {
    mx[p] = mn[p] = oc[p] = vl;
    sm[p] = (r - l + 1) * 1ll * vl;
    return;
  }
  int mid = (l + r) / 2;
  if (ll <= mid) modify(((p) + (p)), l, mid, ll, min(mid, rr), vl);
  if (mid < rr) modify(((p) + (p) + 1), mid + 1, r, max(mid + 1, ll), rr, vl);
  sm[p] = sm[((p) + (p))] + sm[((p) + (p) + 1)];
  mx[p] = max(mx[((p) + (p))], mx[((p) + (p) + 1)]);
  mn[p] = min(mn[((p) + (p))], mn[((p) + (p) + 1)]);
}
void work() {
  vector<int> vp;
  int k;
  A[200001] = n * 1ll * (n + 1) - sm[1];
  for (int i = (200000), _END_ = (1); i >= _END_; i--) {
    vp.clear();
    for (int j = i; j <= 200000; j += i)
      if (pos[j]) vp.push_back(pos[j]);
    sort(vp.begin(), vp.end());
    k = vp.size();
    if (k >= 2) {
      modify(1, 1, n, vp[1] + 1, n, n + 1);
      modify(1, 1, n, 1, vp[k - 2] - 1, vp[k - 2]);
      modify(1, 1, n, vp[0] + 1, vp[k - 1] - 1, vp[k - 1]);
    }
    A[i] = n * 1ll * (n + 1) - sm[1];
  }
  for (int i = (1), _END_ = (200000); i <= _END_; i++)
    ans += (A[i + 1] - A[i]) * i;
  printf("%I64d\n", ans);
}
int main() {
  int _ = 0;
  init();
  built(1, 1, n);
  work();
  close();
  return 0;
}
