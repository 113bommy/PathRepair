#include <bits/stdc++.h>
using namespace std;
int p[10100];
int cnt[10100];
int find(int x) {
  if (p[x] == x)
    return x;
  else
    return p[x] = find(p[x]);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    if (find(i) != find(m)) {
      p[find(i)] = find(m);
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt[find(i)] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) ans++;
  }
  cout << ans << endl;
}
