#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
long long n, sum[maxn << 2], lazy[maxn << 2], mn[maxn << 2], mx[maxn << 2],
    ans[maxn];
vector<int> divs[maxn], ms[maxn];
void build(int id = 1, int l = 0, int r = n) {
  lazy[id] = -1;
  if (r - l < 2) {
    sum[id] = mn[id] = mx[id] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid, r);
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
  mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
  mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
void put(long long x, int id, int l, int r) {
  lazy[id] = mn[id] = mx[id] = x;
  sum[id] = 1LL * x * (r - l);
}
void shift(int id, int l, int r) {
  if (r - l > 1 && lazy[id] != -1) {
    int mid = (l + r) >> 1;
    put(lazy[id], id << 1, l, mid);
    put(lazy[id], id << 1 | 1, mid, r);
  }
  lazy[id] = -1;
}
void update(int L, int R, long long x, int id = 1, int l = 0, int r = n) {
  if (R <= L || R <= l || r <= L || mn[id] >= x) return;
  if (L <= l && r <= R && mx[id] < x) {
    put(x, id, l, r);
    return;
  }
  shift(id, l, r);
  int mid = (l + r) >> 1;
  update(L, R, x, id << 1, l, mid);
  update(L, R, x, id << 1 | 1, mid, r);
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
  mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
  mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  build();
  for (long long i = 1; i < maxn; i++) {
    for (long long j = i; j < maxn; j += i) divs[j].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int x : divs[a[i]]) {
      ms[x].push_back(i);
    }
  }
  for (int i = maxn - 1; i >= 0; i--) {
    ans[i] = n * n - sum[1];
    if (ms[i].size() < 2) continue;
    update(0, ms[i][0] + 1, ms[i][ms[i].size() - 2]);
    update(ms[i][0] + 1, ms[i][1] + 1, ms[i].back());
    update(ms[i][1] + 1, n, n);
  }
  long long res = 0;
  for (long long i = 1; i < 7; i++) {
    res += i * (ans[i] - ans[i - 1]);
  }
  cout << res << endl;
  return 0;
}
