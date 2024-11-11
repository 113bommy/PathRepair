#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, i, j, a, b;
  cin >> n >> a >> b;
  vector<long long> c(n), pos;
  for (i = 0; i < n; i++) {
    cin >> c[i];
    if (c[i] == 2) pos.push_back(i);
  }
  i = 0;
  j = n - 1;
  while (i <= j) {
    if (c[i] == c[j]) {
      if (c[i] == 0 || c[i] == 1) {
        i++;
        j--;
        continue;
      } else {
        c[i] = (a < b) ? 0 : 1;
        c[j] = (a < b) ? 0 : 1;
      }
    } else {
      if (c[i] + c[j] == 1) {
        cout << -1;
        return 0;
      } else {
        long long mn = min(c[i], c[j]);
        c[i] = c[j] = mn;
      }
    }
    i++;
    j--;
  }
  long long ans = 0;
  for (i = 0; i < (long long)((pos).size()); i++) {
    if (c[pos[i]] == 0)
      ans += a;
    else
      ans += b;
  }
  cout << ans;
}
