#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e10;
struct Travolator {
  int l;
  long double v;
  long double L;
  long double R;
};
vector<Travolator> t;
struct Vertex {
  long double p;
  long double minimum;
};
vector<Vertex> rmq;
void push(int i, int l, int r) {
  if (r - l <= 1) return;
  long double P = rmq[i].p;
  rmq[i].p = 0;
  rmq[2 * i + 1].p += P, rmq[2 * i + 1].minimum += P;
  rmq[2 * i + 2].p += P, rmq[2 * i + 2].minimum += P;
}
void add(int i, int l, int r, int l1, int r1, long double first) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    rmq[i].p += first, rmq[i].minimum += first;
    return;
  }
  int mid = (l + r) / 2;
  add(2 * i + 1, l, mid, l1, min(r1, mid), first),
      add(2 * i + 2, mid, r, max(l1, mid), r1, first);
  rmq[i].minimum = min(rmq[2 * i + 1].minimum, rmq[2 * i + 2].minimum);
}
long double get(int i, int l, int r, int l1, int r1) {
  push(i, l, r);
  if (l1 >= r1) return 1e18;
  if (l == l1 && r == r1) return rmq[i].minimum;
  int mid = (l + r) / 2;
  return min(get(2 * i + 1, l, mid, l1, min(r1, mid)),
             get(2 * i + 2, mid, r, max(l1, mid), r1));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    int first, second;
    long double v;
    cin >> first >> second >> v;
    if (first != last) {
      t.push_back({first - last, 1});
    }
    t.push_back({second - first, v + 1});
    last = second;
  }
  if (last != l) t.push_back({l - last, 1});
  n = t.size();
  for (int i = 0; i < n; ++i) {
    long double tm = t[i].l / (t[i].v + 1);
    t[i].L = -tm;
    if (abs(1. - t[i].v) < 1 / INF) {
      t[i].R = INF;
    } else
      t[i].R = t[i].l / (t[i].v - 1);
  }
  rmq.assign(4 * n, {0., 0.});
  vector<pair<long double, int> > arr;
  for (int i = 0; i < n; ++i) arr.push_back({t[i].v, i});
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; ++i) {
    add(0, 0, n, i, n, t[i].R);
  }
  for (int i = 0; i < n; ++i) {
    int index = arr[i].second;
    long double minimum =
        min(get(0, 0, n, index, n),
            (long double)t[index].R - (long double)t[index].L);
    add(0, 0, n, index, n, -minimum);
  }
  long double ans = 0;
  long double old = 0;
  for (int i = 0; i < n; ++i) {
    long double spent = get(0, 0, n, i, i + 1);
    ans += (t[i].l + (spent - old)) / t[i].v;
    old = spent;
  }
  cout.precision(11);
  cout << fixed << ans;
}
