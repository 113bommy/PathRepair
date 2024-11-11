#include <bits/stdc++.h>
using namespace std;
int n, q, k, tmp;
int x[1700007], y[1700007];
int R[1700007], C[1700007];
char dir[1700007];
map<int, int> M;
set<pair<int, int> > seen;
void upd(int san, int a, int b, int l, int r, int node, int *A) {
  if (a <= l && b >= r) {
    A[node] = max(A[node], san);
    return;
  }
  if (a > r || b < l) return;
  upd(san, a, b, l, (l + r) / 2, node * 2, A);
  upd(san, a, b, (l + r) / 2 + 1, r, node * 2 + 1, A);
}
void tap(int x, int l, int r, int node, int *A) {
  k = max(A[node], k);
  if (l == r) return;
  if (x <= (l + r) / 2)
    tap(x, l, (l + r) / 2, node * 2, A);
  else
    tap(x, (l + r) / 2 + 1, r, node * 2 + 1, A);
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> x[i] >> y[i] >> dir[i];
    M[x[i]] = 1;
    M[y[i]] = 1;
  }
  for (auto i : M) M[i.first] = ++tmp;
  for (int i = 0; i < q; i++) {
    swap(x[i], y[i]);
    auto j = seen.find({x[i], y[i]});
    k = 0;
    if (j != seen.end() && j->first == x[i] && j->second == y[i]) {
      cout << "0\n";
      continue;
    }
    if (dir[i] == 'U') {
      tap(M[y[i]], 1, tmp, 1, R);
      upd(y[i], M[k] + 1, M[x[i]], 1, tmp, 1, C);
      cout << x[i] - k << "\n";
    } else {
      tap(M[x[i]], 1, tmp, 1, C);
      upd(x[i], M[k] + 1, M[y[i]], 1, tmp, 1, R);
      cout << y[i] - k << "\n";
    }
    seen.insert({x[i], y[i]});
  }
}
