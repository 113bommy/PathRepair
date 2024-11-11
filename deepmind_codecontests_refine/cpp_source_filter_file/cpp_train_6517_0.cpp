#include <bits/stdc++.h>
using namespace std;
int currpos = 0;
vector<int> tree(100011);
void u(int v, int p, int n) {
  for (int i = p + 1; i <= n; i += (i & (-i))) tree[i] += v;
}
int q(int p) {
  int res = 0;
  for (int i = p + 1; i > 0; i -= (i & (-i))) res += tree[i];
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, k, p, t;
  cin >> n;
  vector<int> A(n);
  set<int> indexes[100011];
  for (int i = 0; i < (n); i++) {
    cin >> A[i];
    indexes[A[i]].insert(i);
    u(1, i, n);
  }
  int res = 0;
  for (int i = 0; i < 100011;) {
    if (indexes[i].empty()) {
      i++;
      continue;
    }
    auto it = indexes[i].lower_bound(currpos);
    if (it == indexes[i].end()) {
      it = indexes[i].begin();
    }
    if (*it < currpos) {
      res += (q(*it) + q(n - 1) - q(currpos - 1));
    } else
      res += q(*it) - q(currpos - 1);
    u(-1, *it, n);
    currpos = *it;
    indexes[i].erase(it);
  }
  cout << res << endl;
  return 0;
}
