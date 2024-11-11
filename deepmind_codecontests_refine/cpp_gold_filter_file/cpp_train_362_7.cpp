#include <bits/stdc++.h>
using namespace std;
int n, m, genre[15], x, ans;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    genre[x]++;
  }
  for (int i = 1; i < m; i++) {
    for (int j = i + 1; j <= m; j++) {
      ans += genre[i] * genre[j];
    }
  }
  cout << ans << '\n';
}
