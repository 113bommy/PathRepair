#include <bits/stdc++.h>
using namespace std;
struct fla {
  bool fls, flo;
  fla next() const { return {flo, fls}; }
};
vector<int> ops;
void dfs(int p, int par, fla f, vector<int> adj[], bool init[], bool goal[]) {
  bool todo = (init[p] != goal[p]) != f.fls;
  if (todo) {
    f.fls = !f.fls;
    ops.push_back(p);
  }
  for (int ch : adj[p])
    if (ch != par) {
      dfs(ch, p, f.next(), adj, init, goal);
    }
}
int main() {
  int n;
  cin >> n;
  vector<int> adj[n];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bool init[n], goal[n];
  for (bool& x : init) cin >> x;
  for (bool& x : goal) cin >> x;
  dfs(0, -1, {false, false}, adj, init, goal);
  cout << ops.size() << endl;
  for (int x : ops) cout << x + 1 << endl;
}
