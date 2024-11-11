#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 1, a, c, b; i <= m; i++) {
    cin >> a >> b >> c;
    v[a] += c;
    v[b] -= c;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] > 0) sum += v[i];
  }
  cout << sum;
  return 0;
}
