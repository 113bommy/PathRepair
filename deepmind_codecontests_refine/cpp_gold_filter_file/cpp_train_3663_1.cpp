#include <bits/stdc++.h>
using namespace std;
pair<int, int> v[1010];
int main() {
  int i, n, sol = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v + 1, v + n + 1);
  for (i = 0; i < n; i++) {
    sol += v[n - i].first * i + 1;
  }
  cout << sol << "\n";
  for (i = n; i >= 1; i--) cout << v[i].second << " ";
  return 0;
}
