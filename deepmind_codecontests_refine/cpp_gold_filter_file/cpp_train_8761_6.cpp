#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
class {
 public:
  int Min0[100009 << 2], Max0[100009 << 2], Min1[100009 << 2],
      Max1[100009 << 2];
  int A[100009], k, n;
  void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
      A[i] = s[i - 1] - '0';
    }
    build(1, 1, n);
    int F = 0, G = 0;
    for (int i = 1; i <= n; i++) {
      if (i + k - 1 > n) break;
      pair<pair<int, int>, pair<int, int> > L = query(1, 1, n, 1, i - 1),
                                            R = query(1, 1, n, i + k, n);
      if ((L.first.first == 100009 && R.first.first == 100009) ||
          (L.second.first == 100009 && R.second.first == 100009)) {
        cout << "tokitsukaze";
        return;
      }
      int g = 0;
      if ((L.first.first == 100009 &&
           R.first.second - R.first.first + 1 <= k) ||
          (L.first.second - L.first.first + 1 <= k &&
           R.first.first == 100009)) {
        g++;
      }
      if ((L.second.first == 100009 &&
           R.second.second - R.second.first + 1 <= k) ||
          (R.second.first == 100009 &&
           L.second.second - L.second.first + 1 <= k))
        g++;
      if (g == 2) F++;
      G++;
    }
    if (F == G) {
      cout << "quailty";
    } else {
      cout << "once again";
    }
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      if (A[l] == 0) {
        Min0[rt] = l;
        Max0[rt] = l;
        Min1[rt] = 100009;
        Max1[rt] = -1;
      } else {
        Min1[rt] = l;
        Max1[rt] = l;
        Min0[rt] = 100009;
        Max0[rt] = -1;
      }
      return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
  }
  void pushup(int rt) {
    Min0[rt] = min(Min0[rt << 1], Min0[rt << 1 | 1]);
    Min1[rt] = min(Min1[rt << 1], Min1[rt << 1 | 1]);
    Max0[rt] = max(Max0[rt << 1], Max0[rt << 1 | 1]);
    Max1[rt] = max(Max1[rt << 1], Max1[rt << 1 | 1]);
  }
  pair<pair<int, int>, pair<int, int> > query(int rt, int l, int r, int L,
                                              int R) {
    pair<pair<int, int>, pair<int, int> > ret = {{100009, -1}, {100009, -1}};
    if (L > R) return ret;
    if (L <= l && R >= r) {
      return make_pair(make_pair(Min0[rt], Max0[rt]),
                       make_pair(Min1[rt], Max1[rt]));
    }
    int mid = l + r >> 1;
    if (L <= mid) {
      pair<pair<int, int>, pair<int, int> > p = query(rt << 1, l, mid, L, R);
      ret.first.first = min(ret.first.first, p.first.first);
      ret.first.second = max(ret.first.second, p.first.second);
      ret.second.first = min(ret.second.first, p.second.first);
      ret.second.second = max(ret.second.second, p.second.second);
    }
    if (R > mid) {
      pair<pair<int, int>, pair<int, int> > p =
          query(rt << 1 | 1, mid + 1, r, L, R);
      ret.first.first = min(ret.first.first, p.first.first);
      ret.first.second = max(ret.first.second, p.first.second);
      ret.second.first = min(ret.second.first, p.second.first);
      ret.second.second = max(ret.second.second, p.second.second);
    }
    return ret;
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
