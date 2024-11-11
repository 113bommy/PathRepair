#include <bits/stdc++.h>
using namespace std;
int n, h;
pair<int, int> x[101110];
int ans[101101];
int k1, k2;
int main() {
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x + 1, x + n + 1);
  k1 = (x[n].first + x[n - 1].first) - (x[2].first + x[1].first);
  int maks, mins;
  maks = mins = x[2].first + x[1].first + h;
  ans[x[1].second] = 1;
  ans[x[2].second] = 2;
  for (int i = 3; i <= n; i++) {
    mins = min(mins, x[i].first + x[i - 1].first);
    maks = max(maks,
               max(x[i].first + x[i - 1].first, x[i].first + x[1].first + h));
    ans[x[i].second] = 2;
  }
  k2 = maks - mins;
  if (k1 < k2) {
    cout << k1 << endl;
    for (int i = 1; i <= n; i++) {
      cout << 1;
      if (i == n)
        cout << endl;
      else
        cout << " ";
    }
  } else {
    cout << k2 << endl;
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
      if (i == n)
        cout << endl;
      else
        cout << " ";
    }
  }
}
