#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1e6;
const long long inf = 1e9 + 7;
const long double PI = acos(-1);
long long bin_pow(long long x, long long y) {
  long long res = 1, base = x;
  while (y) {
    if (y & 1) {
      res *= base;
      res %= inf;
    }
    base *= base;
    base %= inf;
    y /= 2;
  }
  return res;
}
int n, mx, k;
vector<int> g[N];
int was[N], cnt[N];
queue<int> q;
int main() {
  boost();
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      was[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (was[v] != 1 && cnt[v] < 3) {
      cout << "No";
      return 0;
    }
    mx = max(mx, was[v]);
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i];
      if (!was[to]) {
        was[to] = was[v] + 1;
        cnt[to]++;
        q.push(to);
      } else if (was[to] >= was[v] && was[to] != was[v] + 1) {
        cout << "No";
        return 0;
      } else if (was[to]) {
        cnt[to]++;
      }
    }
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (was[i] == mx) {
      num++;
    }
  }
  if (num == 1 && mx == k + 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
