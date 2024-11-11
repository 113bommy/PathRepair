#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("main.in", "r")) freopen("main.in", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int res = 1e9, bestVal;
  for (int val = 0; val <= 100; val++) {
    int Change = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == val) continue;
      if (a[i] < val) Change += abs(a[i] - (val - 1));
      if (a[i] > val) Change += abs(a[i] - (val + 1));
    }
    if (Change < res) {
      res = Change;
      bestVal = val;
    }
  }
  cout << bestVal << ' ' << res << '\n';
  ;
  return 0;
}
