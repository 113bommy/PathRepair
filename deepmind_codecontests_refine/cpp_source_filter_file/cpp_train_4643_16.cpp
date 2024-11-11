#include <bits/stdc++.h>
using namespace std;
string s;
int tree[8000005];
void build(int node, int L, int R) {
  if (L == R) {
    tree[node] = s[L];
    return;
  }
  int mid = (L + R) / 2;
  build(2 * node, L, mid);
  build(2 * node + 1, mid + 1, R);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int L, int R, int l, int r) {
  if (L > r || R < l) return 1e9;
  if (L >= l && R <= r) return tree[node];
  int mid = (L + R) / 2;
  return min(query(2 * node, L, mid, l, r),
             query(2 * node + 1, mid + 1, R, l, r));
}
stack<char> my;
int main() {
  cin >> s;
  int n = s.length();
  build(1, 0, n - 1);
  string res;
  for (int i = 0; i < n; i++) {
    my.push(s[i]);
    int x = query(1, 0, n - 1, i, n - 1);
    while (!my.empty() && my.top() <= x) {
      res += my.top();
      my.pop();
    }
  }
  while (!my.empty()) {
    res += my.top();
    my.pop();
  }
  cout << res << endl;
  return 0;
}
