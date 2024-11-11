#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
vector<int> p;
vector<long long> a;
vector<long long> s;
deque<int> cur;
bool f = true;
void dfs(int v, int k) {
  if (k % 2 == 0) {
    long long mn = 1e9;
    int v1 = cur[int(cur.size()) - 1];
    for (int i : g[v]) {
      mn = min(mn, s[i] - s[v1]);
    }
    if (mn <= 0) f = false;
    if (g[v].size() == 0) mn = 0;
    a[v] = mn;
  } else if (v != 0) {
    int v1 = cur[int(cur.size()) - 1];
    int v2 = cur[int(cur.size()) - 2];
    a[v] = s[v] - s[v2] - a[v1];
  }
  cur.push_back(v);
  for (int i : g[v]) {
    dfs(i, k + 1);
  }
  cur.pop_back();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  p.resize(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    g[p[i]].push_back(i);
  }
  s.resize(n);
  a.resize(n, 0);
  for (int i = 0; i < n; i++) cin >> s[i];
  a[0] = s[0];
  dfs(0, 1);
  if (!f) {
    cout << -1;
    return 0;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  cout << sum;
  return 0;
}
