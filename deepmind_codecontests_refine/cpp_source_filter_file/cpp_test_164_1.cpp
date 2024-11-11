#include <bits/stdc++.h>
using namespace std;
const int w = 200010;
int n, k;
string s;
int l[w], r[w];
bool good[w];
bool cpy[w];
vector<int> vec;
void build(int u) {
  if (l[u]) build(l[u]);
  vec.push_back(u);
  if (r[u]) build(r[u]);
}
void dfs(int u, int cnt) {
  if (cnt > k) return;
  if (l[u]) dfs(l[u], cnt + 1);
  if (cpy[l[u]]) {
    cpy[u] = true;
  } else if (good[u]) {
    cpy[u] = true;
    k -= cnt;
  }
  if (cpy[u] && r[u]) dfs(r[u], 1);
}
int main() {
  cin >> n >> k;
  cin >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    l[i] = a, r[i] = b;
  }
  build(1);
  char last = s[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    int a = vec[i], b = vec[i + 1];
    if (s[a] != s[b]) {
      last = s[b];
    }
    if (s[a] < last) {
      good[a] = true;
    }
  }
  dfs(1, 1);
  for (int i = 0; i < vec.size(); i++) {
    int t = vec[i];
    cout << s[t];
    if (cpy[t]) cout << s[t];
  }
  cout << endl;
  return 0;
}
