#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long cnt[1000000];
long long it[1000000];
int n, k, m;
struct wtf {
  long long l, r, d;
};
wtf mo[1000000];
void build(int k, int l, int r) {
  if (l == r) {
    it[k] = a[l];
  } else {
    int mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
  }
}
void down(int k) {
  if (it[k] > 0) {
    it[k << 1] += it[k];
    it[k << 1 | 1] += it[k];
    it[k] = 0;
  }
}
void down2(int k) {
  if (cnt[k] > 0) {
    cnt[k << 1] += cnt[k];
    cnt[k << 1 | 1] += cnt[k];
    cnt[k] = 0;
  }
}
void update(int k, int l, int r, int lq, int rq, long long val) {
  if (lq > r || rq < l) return;
  if (lq <= l && r <= rq)
    it[k] += val;
  else {
    down(k);
    int mid = (l + r) / 2;
    update(k << 1, l, mid, lq, rq, val);
    update(k << 1 | 1, mid + 1, r, lq, rq, val);
  }
}
void update2(int k, int l, int r, int lq, int rq) {
  if (lq > r || rq < l) return;
  if (lq <= l && r <= rq)
    cnt[k]++;
  else {
    down2(k);
    int mid = (l + r) / 2;
    update2(k << 1, l, mid, lq, rq);
    update2(k << 1 | 1, mid + 1, r, lq, rq);
  }
}
void output(int k, int l, int r) {
  if (l == r) {
    cout << it[k] << " ";
  } else {
    down(k);
    int mid = (l + r) / 2;
    output(k << 1, l, mid);
    output(k << 1 | 1, mid + 1, r);
  }
}
void output2(int k, int l, int r) {
  if (l == r) {
    if (cnt[k]) {
      update(1, 1, n, mo[l].l, mo[l].r, mo[l].d * cnt[k]);
    }
  } else {
    down2(k);
    int mid = (l + r) / 2;
    output2(k << 1, l, mid);
    output2(k << 1 | 1, mid + 1, r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int lq, rq, val, x, y;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> mo[i].l >> mo[i].r >> mo[i].d;
  }
  build(1, 1, n);
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    update2(1, 1, m, x, y);
  }
  output2(1, 1, m);
  output(1, 1, n);
  return 0;
}
