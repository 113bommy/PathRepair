#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const int N = 200100;
int n, a[N], b[N];
map<int, int> done, ind;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[a[i]] = i;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = ind[b[i]]; j >= 0; j--) {
      if (!done[a[j]]) {
        ans++;
        done[a[j]] = 1;
      } else
        break;
    }
    cout << ans << ' ';
  }
  return 0;
}
