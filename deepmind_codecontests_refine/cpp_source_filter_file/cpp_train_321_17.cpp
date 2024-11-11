#include <bits/stdc++.h>
using namespace std;
const int MD = 1000000007;
const int INF = 1e9 + 9;
const int N = 1e3 + 33;
long long n, m, k;
vector<int> g[N];
int my[N], opp[N];
int mark[N];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      mark[i] = 0;
      my[i] = 0;
      opp[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a - 1].push_back(b - 1);
      g[b - 1].push_back(a - 1);
    }
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      my[a - 1] = 1;
    }
    cin >> k;
    int qq;
    while (k--) {
      int a;
      cin >> a;
      qq = a;
      opp[a - 1] = 1;
    }
    cout << "B " << qq << endl;
    int x;
    cin >> x;
    if (my[x - 1] == 1) {
      cout << "C " << x << endl;
      continue;
    }
    queue<int> bfsq;
    bfsq.push(x - 1);
    while (!bfsq.empty()) {
      int v = bfsq.front();
      mark[v] = 1;
      bfsq.pop();
      for (int u : g[v]) {
        if (my[u] == 1) {
          cout << "A " << u + 1 << endl;
          int y;
          cin >> y;
          if (opp[y - 1] == 1) {
            cout << "C " << y << endl;
            break;
          } else {
            cout << "C " << -1 << endl;
            break;
          }
        }
        if (mark[u] == 0) bfsq.push(u);
      }
    }
  }
  return 0;
}
