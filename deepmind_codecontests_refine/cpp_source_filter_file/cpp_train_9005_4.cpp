#include <bits/stdc++.h>
using namespace std;
const int MAX = 100100;
const int MAX4 = MAX * 4;
int N, Q, l, r, x;
int A[MAX];
int b[MAX4], e[MAX4], lo[MAX4], hi[MAX4];
void init(int n, int beg, int end) {
  b[n] = beg;
  e[n] = end;
  if (beg == end) {
    lo[n] = hi[n] = beg;
    return;
  }
  int m = beg + (end - beg) / 2;
  init(2 * n, beg, m);
  init(2 * n + 1, m + 1, end);
  lo[n] = lo[2 * n];
  if (A[lo[2 * n + 1]] < A[lo[n]]) lo[n] = lo[2 * n + 1];
  hi[n] = hi[2 * n];
  if (A[hi[2 * n + 1]] > A[hi[n]]) hi[n] = hi[2 * n + 1];
}
pair<int, int> query(int n) {
  if (b[n] >= l && e[n] <= r) {
    return {lo[n], hi[n]};
  }
  pair<int, int> ret;
  if (e[2 * n] >= l) {
    ret = query(2 * n);
    if (b[2 * n + 1] <= r) {
      pair<int, int> tmp = query(2 * n + 1);
      if (A[tmp.first] < A[ret.first]) ret.first = tmp.first;
      if (A[tmp.second] > A[ret.second]) ret.second = tmp.second;
    }
    return ret;
  } else
    return query(2 * n + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (int I = 0; I < N; I++) cin >> A[I];
  init(1, 0, N - 1);
  for (int q = 0; q < Q; q++) {
    cin >> l >> r >> x;
    l--;
    r--;
    pair<int, int> sol = query(1);
    if (A[sol.first] != x)
      cout << sol.first + 1 << "\n";
    else if (A[sol.second] != x)
      cout << sol.second + 1 << "\n";
    else
      cout << -1 << "\n";
  };
}
