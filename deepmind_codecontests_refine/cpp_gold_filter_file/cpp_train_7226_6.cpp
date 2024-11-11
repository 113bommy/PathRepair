#include <bits/stdc++.h>
using namespace std;
const int mxq = 100000;
const int mxn = 4000000;
string S;
int Q, N;
int L[mxq], R[mxq];
int O[mxn], C[mxn], A[mxn];
void build(int idx, int l, int r) {
  if (r - l < 2) {
    if (S[l] == '(') {
      O[idx] = 1;
    } else {
      C[idx] = 1;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid, r);
  int tmp = min(O[idx << 1], C[idx << 1 | 1]);
  A[idx] = A[idx << 1] + A[idx << 1 | 1] + tmp;
  O[idx] = O[idx << 1] + O[idx << 1 | 1] - tmp;
  C[idx] = C[idx << 1] + C[idx << 1 | 1] - tmp;
}
pair<int, pair<int, int> > query(int x, int y, int idx, int l, int r) {
  if (l >= y || x >= r)
    return pair<int, pair<int, int> >(0, pair<int, int>(0, 0));
  if (x <= l && r <= y)
    return pair<int, pair<int, int> >(A[idx], pair<int, int>(O[idx], C[idx]));
  int mid = (l + r) >> 1;
  pair<int, pair<int, int> > left = query(x, y, idx << 1, l, mid);
  pair<int, pair<int, int> > right = query(x, y, idx << 1 | 1, mid, r);
  int tmp = min(left.second.first, right.second.second);
  int ans = left.first + right.first + tmp;
  int opn = left.second.first + right.second.first - tmp;
  int cls = left.second.second + right.second.second - tmp;
  return pair<int, pair<int, int> >(ans, pair<int, int>(opn, cls));
}
int main() {
  cin >> S;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> L[q] >> R[q];
    L[q]--;
  }
  N = S.size();
  for (int i = 0; i < N << 1; i++) {
    A[i] = 0;
    O[i] = 0;
    C[i] = 0;
  }
  build(1, 0, N);
  for (int q = 0; q < Q; q++) {
    pair<int, pair<int, int> > res = query(L[q], R[q], 1, 0, N);
    cout << 2 * res.first << '\n';
  }
}
