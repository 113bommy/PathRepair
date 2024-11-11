#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  long long val, leaf;
  friend bool operator<(node a, node b) {
    return ((a.val - a.val / 2) * a.leaf) < ((b.val - b.val / 2) * b.leaf);
  }
};
int e[N], ne[N], h[N], w[N], idx, n;
long long s, sum, ans;
priority_queue<node> q;
void add(int a, int b, int c) {
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}
long long dfs(int pre, int cur) {
  long long leaf = 0;
  for (int i = h[cur]; ~i; i = ne[i]) {
    int to = e[i];
    if (to != pre) {
      long long temp = dfs(cur, to);
      q.push({w[i], temp});
      sum += w[i] * temp;
      leaf += temp;
    }
  }
  if (leaf)
    return leaf;
  else
    return 1;
}
int main() {
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    while (q.size()) q.pop();
    memset(h, -1, sizeof h);
    idx = sum = ans = 0;
    for (int i = 1; i < n; i++) {
      cin >> a >> b >> c;
      add(a, b, c);
      add(b, a, c);
    }
    dfs(0, 1);
    while (sum > s) {
      long long val = q.top().val;
      long long leaf = q.top().leaf;
      q.pop();
      sum -= (val - val / 2) * leaf;
      val /= 2;
      q.push({val, leaf});
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
