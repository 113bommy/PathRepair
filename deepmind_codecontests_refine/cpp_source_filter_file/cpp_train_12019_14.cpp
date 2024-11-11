#include <bits/stdc++.h>
using namespace std;
int n, ans;
int v[510009], pr[510009], ne[510009];
bool vis[510009];
queue<int> q;
void tap(int x) {
  if (vis[x]) return;
  if (v[pr[x]] >= v[x] && v[x] <= v[ne[x]]) vis[x] = 1, q.push(x);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  ne[0] = 1, pr[n + 1] = n;
  for (int i = 1; i <= n; i++) tap(i);
  while (q.size()) {
    int k = q.front();
    q.pop();
    ne[pr[k]] = ne[k];
    pr[ne[k]] = pr[k];
    ans += min(v[pr[k]], v[ne[k]]);
    tap(pr[k]);
    tap(ne[k]);
  }
  int k = ne[0];
  while (k != n + 1) {
    ans += min(v[pr[k]], v[ne[k]]), k = ne[k];
  }
  cout << ans;
}
