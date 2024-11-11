#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, b, k, ans, menor, i;
  cin >> n >> b;
  vector<int> V(n);
  for (i = 0; i < n; i++) {
    cin >> V[i];
  }
  menor = V[0];
  ans = b;
  for (i = 1; i < n; i++) {
    k = b / menor;
    ans = max(ans, b + k * (V[i] - menor));
    menor = min(menor, V[i]);
  }
  cout << ans << '\n';
}
