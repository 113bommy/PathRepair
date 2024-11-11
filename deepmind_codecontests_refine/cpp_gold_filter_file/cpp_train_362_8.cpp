#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, g;
  cin >> n >> m;
  int count[m];
  fill(count, count + m, 0);
  for (int i = 0; i < n; i++) {
    cin >> g;
    count[g - 1]++;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) ans += count[i] * (n - count[i]);
  cout << ans / 2 << endl;
  return 0;
}
