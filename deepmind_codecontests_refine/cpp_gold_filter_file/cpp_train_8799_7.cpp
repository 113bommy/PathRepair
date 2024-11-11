#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, k, ans = 0, x;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> x;
      for (int harshil = 0; harshil < k; harshil++) {
        if (a[harshil] == x) {
          ans += harshil;
          a.erase(a.begin() + harshil);
          a.insert(a.begin(), x);
          break;
        }
      }
    }
  }
  cout << ans + n * m;
  return 0;
}
