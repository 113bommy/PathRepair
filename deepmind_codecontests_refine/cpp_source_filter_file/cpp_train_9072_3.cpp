#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e3 + 4;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k, graph[N][N], so_be[N][N], cnt = 0;
string s[N];
queue<pair<int, int> > q;
pair<int, int> trace[N][N];
int Max_;
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  m = n / 2 + 1;
  cout << m << endl;
  for (int i = 1; i <= m; i++) cout << 1 << ' ' << i << endl;
  for (int i = 1; i <= n - m; i++) cout << m << ' ' << i << endl;
}
void solve() { int l = 1, r = (int)1e6; }
int main() {
  init();
  solve();
  return 0;
}
