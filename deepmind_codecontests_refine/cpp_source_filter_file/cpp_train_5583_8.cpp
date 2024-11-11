#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 1;
const int maxk = 11;
int n, k;
struct node {
  int mn[maxk], mx[maxk];
  int cnt;
  bool operator<(const node& x) const {
    for (int i = 1; i <= k; i++) {
      if (mx[i] < x.mn[i]) return false;
    }
    return true;
  }
  void merge(const node& x) {
    cnt += x.cnt;
    for (int i = 1; i <= k; i++) {
      mn[i] = min(mn[i], x.mn[i]);
      mx[i] = max(mx[i], x.mx[i]);
    }
  }
};
set<node> dag;
int main() {
  cin >> n >> k;
  for (int i = 1, s; i <= n; i++) {
    node tmp;
    for (int j = 1; j <= k; j++) {
      cin >> s;
      tmp.mn[j] = tmp.mx[j] = s;
    }
    tmp.cnt = 1;
    auto lb = dag.lower_bound(tmp);
    auto ub = dag.upper_bound(tmp);
    while (lb != ub) {
      tmp.merge(*lb);
      lb = dag.erase(lb);
    }
    dag.insert(tmp);
    cout << dag.begin()->cnt << endl;
  }
  return 0;
}
