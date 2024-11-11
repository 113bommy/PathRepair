#include <bits/stdc++.h>
using namespace std;
struct segtree {
  pair<long long, long long> T[100100];
  int n;
  void update(int init, int fim, int p, int pos, long long val) {
    if (pos > fim || pos < init) return;
    if (init == fim) {
      T[p].first = T[p].second = val;
      return;
    }
    int mid = (init + fim) / 2;
    update(init, mid, 2 * p, pos, val);
    update(mid + 1, fim, 2 * p + 1, pos, val);
    T[p].first = max(T[2 * p].first, T[2 * p + 1].first);
    T[p].second = min(T[2 * p].second, T[2 * p + 1].second);
  }
  pair<long long, long long> query(int init, int fim, int p, int l, int r) {
    if (l > fim || r < init)
      return pair<long long, long long>(-(999999999999LL), (999999999999LL));
    if (init >= l && fim <= r) return T[p];
    int mid = (init + fim) / 2;
    pair<long long, long long> A = query(init, mid, 2 * p, l, r);
    pair<long long, long long> B = query(mid + 1, fim, 2 * p + 1, l, r);
    return pair<long long, long long>(max(A.first, B.first),
                                      min(A.second, B.second));
  }
  void build(int N, int* v) {
    n = N;
    for (int i = 0; i < n; i++) update(0, n - 1, 1, i, v[i]);
  }
};
int v[100100];
int nil[100100];
segtree arr;
segtree dp;
int main() {
  long long n, s, l;
  cin >> n >> s >> l;
  for (int i = 0; i < n; i++) nil[i] = 0;
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  arr.build(n, v);
  dp.build(n + 1, nil);
  int righty = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    while (righty > i) {
      pair<long long, long long> k = arr.query(0, n - 1, 1, i, righty);
      if (k.first - k.second > s)
        righty--;
      else
        break;
    }
    int lefty = i + l - 1;
    long long ans;
    if (lefty > righty)
      ans = (999999999999LL);
    else
      ans = 1 +
            dp.query(0, n, 1, lefty + 1, min(n, (long long)righty + 1)).second;
    ;
    dp.update(0, n, 1, i, ans);
  }
  long long resp = dp.query(0, n, 1, 0, 0).first;
  if (resp == (999999999999LL))
    printf("-1\n");
  else
    cout << resp << endl;
}
