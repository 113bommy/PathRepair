#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 100 * 10 + 10;
pair<long long, long long> maxx[4 * maxn];
long long sum[4 * maxn], a[maxn];
pair<long long, long long> getmax(int l, int r, int ind, int b, int e) {
  pair<long long, long long> ret1, ret2, ret3;
  ret1 = ret2 = ret3 = make_pair(0, 0);
  if (l <= b && e <= r) {
    return maxx[ind];
  }
  int mid = (b + e) / 2;
  if (l < mid) {
    ret1 = getmax(l, r, ind * 2, b, mid);
  }
  if (r > mid) {
    ret2 = getmax(l, r, ind * 2 + 1, mid, e);
  }
  ret3 = max(ret1, ret2);
  return ret3;
}
void make(int ind, int b, int e) {
  if (e - b == 1) {
    sum[ind] = a[b];
    maxx[ind].first = a[b];
    maxx[ind].second = b;
    return;
  }
  int mid = (b + e) / 2;
  make(ind * 2, b, mid);
  make(ind * 2 + 1, mid, e);
  maxx[ind] = max(maxx[ind * 2], maxx[ind * 2 + 1]);
  sum[ind] = sum[ind * 2] + sum[ind * 2 + 1];
  return;
}
void change(int p, long long val, int ind, int b, int e) {
  if (e - b == 1) {
    sum[ind] = val;
    maxx[ind].first = val;
    return;
  }
  int mid = (b + e) / 2;
  if (p < mid)
    change(p, val, ind * 2, b, mid);
  else
    change(p, val, ind * 2 + 1, mid, e);
  maxx[ind] = max(maxx[ind * 2], maxx[ind * 2 + 1]);
  sum[ind] = sum[ind * 2] + sum[ind * 2 + 1];
  return;
}
long long get(int l, int r, int ind, int b, int e) {
  long long ret = 0;
  if (l <= b && e <= r) {
    return sum[ind];
  }
  int mid = (b + e) / 2;
  if (l < mid) ret += get(l, r, ind * 2, b, mid);
  if (r > mid) ret += get(l, r, ind * 2 + 1, mid, e);
  sum[ind] = sum[ind * 2] + sum[ind * 2 + 1];
  return ret;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, m, type, u, k, x, t, l, r;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  make(1, 0, n);
  for (int i = 0; i < m; i++) {
    cin >> type;
    if (type == 1) {
      cin >> l >> r;
      cout << get(l - 1, r, 1, 0, n) << endl;
    } else if (type == 2) {
      cin >> l >> r >> x;
      l--;
      while (getmax(l, r, 1, 0, n).first >= x) {
        u = getmax(l, r, 1, 0, n).second;
        change(u, getmax(l, r, 1, 0, n).first % x, 1, 0, n);
      }
    } else {
      cin >> k >> x;
      k--;
      change(k, x, 1, 0, n);
    }
  }
  return 0;
}
