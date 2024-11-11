#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
vector<pair<int, int> > cu;
int sum[1002];
void solve(int n) {
  if (cu[n - 1].first == n) {
    int u = n - 1;
    for (int i = 0; i < n; i++) a[cu[n - 1].second][i] = 1;
    while (u - 1 >= 0 && cu[u - 1].first == n) {
      u--;
      a[cu[u].second][n] = 1;
      cu[u].first--;
    }
    if (n != 1) solve(n - 1);
    for (int i = 0; i < n; i++) sum[i]++;
    sum[n] += n - 1 - u;
  } else {
    solve(n - 1);
    a[cu[n - 1].second][n] = 1;
    sum[n]++;
    cu[n - 1].first--;
    for (int i = 0; i < n; i++) {
      if (sum[i] != 0 && cu[n - 1].first > 0) {
        cu[n - 1].first--;
        sum[i]++;
        a[cu[n - 1].second][i] = 1;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> cap;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    cu.push_back({xi, i});
  }
  sort(cu.begin(), cu.end());
  solve(n);
  cout << n + 1 << endl;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n; j++) cout << a[j][i];
    cout << endl;
  }
  return 0;
}
