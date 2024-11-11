#include <bits/stdc++.h>
using namespace std;
int v[100001], w[100001];
bool c[100001];
int main() {
  int n, m, x;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = n; i > 0; i--)
    if (c[v[i]] == false) {
      c[v[i]] = true;
      w[i]++;
    }
  for (int i = n; i > 0; i--) w[i] += w[i + 1];
  for (int i = 1; i <= m; i++) {
    cin >> x;
    cout << w[x] << " ";
  }
  return 0;
}
