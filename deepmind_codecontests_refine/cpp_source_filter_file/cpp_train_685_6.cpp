#include <bits/stdc++.h>
using namespace std;
struct Ftree {
  vector<int64_t> dat;
  Ftree(int size) : dat(size) {}
  void add(int k, int v) {
    for (int i = k; i < dat.size(); i += i & -i) {
      dat[i] += v;
    }
  }
  void clear(int k) {
    for (int i = k; i < dat.size(); i += i & -i) {
      dat[i] = 0;
    }
  }
  int sum(int k) {
    int64_t s = 0;
    for (int i = k; i; i -= i & -i) {
      s += dat[i];
    }
    return s;
  }
};
signed main() {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<tuple<int, int, int, int>> qry;
  vector<int> a(N);
  vector<set<int>> pos(N + 1);
  auto update = [&](int x, int y) {
    if (a[x] == y) return;
    auto add = [&](int v, int w) {
      if (w == 1) pos[v].emplace(x);
      auto it = pos[v].find(x);
      if (it != pos[v].begin()) {
        qry.emplace_back(0, *prev(it) + 1, x + 1, w * (x - *prev(it)));
      }
      if (next(it) != pos[v].end()) {
        qry.emplace_back(0, x + 1, *next(it) + 1, w * (*next(it) - x));
      }
      if (it != pos[v].begin() && next(it) != pos[v].end()) {
        qry.emplace_back(0, *prev(it) + 1, *next(it) + 1,
                         -w * (*next(it) - *prev(it)));
      }
      if (w == -1) pos[v].erase(it);
    };
    if (a[x]) add(a[x], -1);
    add(a[x] = y, 1);
  };
  for (int i = 0; i < N; ++i) {
    update(i, A[i]);
  }
  int qcnt = 0;
  for (int i = 0; i < M; ++i) {
    int C, X, Y;
    cin >> C >> X >> Y;
    if (C == 1) {
      update(X - 1, Y);
    } else {
      ++qcnt;
      qry.emplace_back(qcnt, Y, Y, 1);
      qry.emplace_back(qcnt, X - 1, Y, -1);
      qry.emplace_back(qcnt, Y, X - 1, -1);
      qry.emplace_back(qcnt, X - 1, X - 1, 1);
    }
  }
  vector<int64_t> ans(qcnt);
  Ftree ft(1 << 17);
  function<void(int, int)> cdq = [&](int lb, int rb) {
    if (rb - lb < 2) return;
    int mb = lb + rb >> 1;
    cdq(lb, mb);
    cdq(mb, rb);
    vector<tuple<int, int, int, int>> sorted(rb - lb);
    int p = lb, q = mb, t = 0;
    while (p < mb && q < rb) {
      if (get<1>(qry[p]) <= get<1>(qry[q])) {
        if (get<0>(qry[p]) == 0) {
          ft.add(get<2>(qry[p]), get<3>(qry[p]));
        }
        sorted[t++] = qry[p++];
      } else {
        if (get<0>(qry[q]) != 0) {
          ans[get<0>(qry[q]) - 1] +=
              1LL * ft.sum(get<2>(qry[q])) * get<3>(qry[q]);
        }
        sorted[t++] = qry[q++];
      }
    }
    while (p < mb) {
      sorted[t++] = qry[p++];
    }
    while (q < rb) {
      if (get<0>(qry[q]) != 0) {
        ans[get<0>(qry[q]) - 1] +=
            1LL * ft.sum(get<2>(qry[q])) * get<3>(qry[q]);
      }
      sorted[t++] = qry[q++];
    }
    for (int i = lb; i < rb; ++i) {
      if (get<0>(qry[i]) == 0) {
        ft.clear(get<2>(qry[i]));
      }
      qry[i] = sorted[i - lb];
    }
  };
  cdq(0, qry.size());
  for (int i = 0; i < qcnt; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
