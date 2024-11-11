#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,no-stack-protector")
using namespace std;
int tree[500000];
void change(int v, int l, int r, int pos, int val) {
  if (r - l == 1) {
    tree[v] = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos < m)
    change(v * 2 + 1, l, m, pos, val);
  else
    change(v * 2 + 2, m, r, pos, val);
  tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}
int ask(int v, int l, int r, int askl, int askr) {
  if (r <= askl || askr <= l) return 0;
  if (askl <= l || r <= askr) {
    return tree[v];
  }
  int m = (l + r) / 2;
  return max(ask(v * 2 + 1, l, m, askl, askr),
             ask(v * 2 + 2, m, r, askl, askr));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> p;
  vector<int> ans(n);
  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    char tp;
    cin >> tp;
    if (tp == '+') {
      p.insert({i, cnt++});
    } else {
      int val;
      cin >> val;
      int res = ask(0, 0, n + 1, val + 1, n + 1);
      auto it = p.lower_bound({res, 0});
      if (it == p.end()) {
        cout << "NO";
        return 0;
      }
      ans[it->second] = val;
      p.erase(it);
      change(0, 0, n + 1, val, i + 1);
    }
  }
  cout << "YES" << endl;
  for (int i : ans) cout << i << " ";
}
