#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int tr[60];
int root(int i) {
  if (tr[i] == i) return i;
  return tr[i] = root(tr[i]);
}
void connect(int x, int y) { tr[root(x)] = root(y); }
int main() {
  cin.sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) tr[i] = i;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    connect(b, a);
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    {
      if (tr[i] != i) ans *= 2;
    }
  }
  cout << ans;
}
