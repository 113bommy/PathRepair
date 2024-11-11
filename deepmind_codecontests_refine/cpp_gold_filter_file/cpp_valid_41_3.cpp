#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9;
int n, m, v[maxn], l[maxn], ans[maxn], r[maxn], p[maxn];
char c;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    v[i] = c - 'a';
  }
  vector<int> k;
  for (int i = 0; i < 3; i++) k.push_back(i);
  for (int i = 1; i <= m; i++) ans[i] = inf;
  for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
  do {
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + (k[i % 3] != v[i]);
    }
    for (int i = 1; i <= m; i++) ans[i] = min(ans[i], p[r[i]] - p[l[i] - 1]);
  } while (next_permutation(k.begin(), k.end()));
  for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}
