#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < (n); i++) cin >> a[i];
  int tm = -1, mc = INT_MAX;
  for (int t = 1; t <= (100); t++) {
    int cost = 0;
    for (int i = 0; i < (n); i++) {
      cost += min(abs(a[i] - t), min(abs(a[i] - t + 1), abs(a[i] - t - 1)));
    }
    if (cost < mc) {
      mc = cost;
      tm = t;
    }
  }
  cout << tm << " " << mc << '\n';
  return 0;
}
