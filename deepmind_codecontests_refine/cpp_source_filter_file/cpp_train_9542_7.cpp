#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int INF = 1e9;
string a[maxN];
int c[maxN], p[maxN], ans[maxN];
map<string, int> mp;
int get(int v) {
  if (p[v] == v) return v;
  p[v] = get(p[v]);
  return p[v];
}
void unite(int a, int b) {
  a = get(a), b = get(b);
  if (rand() & 1) swap(a, b);
  p[a] = b;
}
void solveTask() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) mp[a[i]] = i;
  for (int i = 1; i <= n; ++i) p[i] = i;
  for (int i = 1; i <= k; ++i) {
    int cnt;
    cin >> cnt;
    int la = 0;
    for (int j = 1; j <= cnt; ++j) {
      int cur;
      cin >> cur;
      if (la) unite(cur, la);
      la = cur;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] = INF;
  }
  for (int i = 1; i <= n; ++i) {
    ans[get(i)] = min(ans[get(i)], c[i]);
  }
  long long answer = 0;
  for (int i = 1; i <= m; ++i) {
    string t;
    cin >> t;
    int ind = mp[t];
    answer += ans[get(ind)];
  }
  cout << answer << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solveTask();
  return 0;
}
