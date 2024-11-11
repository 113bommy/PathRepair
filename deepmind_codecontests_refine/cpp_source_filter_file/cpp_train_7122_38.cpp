#include <bits/stdc++.h>
using namespace std;
void MAZEN() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  MAZEN();
  int a, b, c, n, m, sum = 0;
  cin >> n >> m;
  vector<int> v(101, 0);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    v[a] -= c;
    v[b] += c;
  }
  for (int i = 0; i < n; i++) sum += v[i] > 0 ? v[i] : 0;
  cout << sum << endl;
  return 0;
}
