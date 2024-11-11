#include <bits/stdc++.h>
const long long inf = std::numeric_limits<long long>::max();
const long long mod = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
stack<int> s;
vector<int> g[1100];
int xx, yy;
bool done;
void dfs(int v, int p) {
  if (done) return;
  for (auto i : g[v]) {
    if (i == p) continue;
    if (i == yy || done) {
      done = true;
      break;
    }
    s.push(i);
    dfs(i, v);
    if (!done) s.pop();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 1100; i++) g[i].clear();
    while (!s.empty()) s.pop();
    set<int> x, y;
    xx = yy = 0;
    done = false;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int x1, y1;
      cin >> x1 >> y1;
      x1--, y1--;
      g[x1].push_back(y1);
      g[y1].push_back(x1);
    }
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
      int v;
      cin >> v;
      v--;
      x.insert(v);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
      int v;
      cin >> v;
      v--;
      y.insert(v);
    }
    yy = *y.begin();
    cout << "B " << yy + 1 << endl;
    cin >> yy;
    yy--;
    xx = *x.begin();
    s.push(xx);
    if (x.find(yy) != x.end()) {
      cout << "C " << yy + 1 << endl;
      continue;
    }
    dfs(xx, -1);
    while (!s.empty() && x.find(s.top()) == x.end()) s.pop();
    cout << "A " << s.top() + 1 << endl;
    int ccc;
    cin >> ccc;
    ccc--;
    if (y.find(ccc) == y.end()) {
      cout << "C -1" << endl;
    } else {
      cout << "C " << s.top() + 1 << endl;
    }
  }
  return 0;
}
