#include <bits/stdc++.h>
using namespace std;
struct segtree {
  vector<long long int> ST;
  segtree(int n) { ST.resize(5 * n + 5, 0); }
  void Build(vector<long long int> &A, int v, int tl, int tr) {
    if (tl == tr) {
      ST[v] = A[tl];
    } else {
      int tm = (tl + tr) / 2;
      Build(A, v * 2, tl, tm);
      Build(A, v * 2 + 1, tm + 1, tr);
      ST[v] = ST[v * 2] + ST[v * 2 + 1];
    }
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return ST[v];
    }
    int tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm)) +
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void modify(int v, int tl, int tr, int pos, long long int val) {
    if (tl == tr) {
      ST[v] = val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        modify(v * 2, tl, tm, pos, val);
      } else {
        modify(v * 2 + 1, tm + 1, tr, pos, val);
      }
      ST[v] = ST[v * 2] + ST[v * 2 + 1];
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long int N = 1e6 + 2;
  segtree ST(N);
  long long calc = 0;
  for (int i = 1; i <= n; i++) {
    int act;
    cin >> act;
    calc = calc + ST.query(1, 0, N, act, N);
    ST.modify(1, 0, N, act, 1);
  }
  if (calc % 2 == 1) {
    cout << "Petr";
  } else {
    cout << "Um_nik";
  }
  return 0;
}
