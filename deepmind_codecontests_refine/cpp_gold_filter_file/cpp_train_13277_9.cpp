#include <bits/stdc++.h>
const int mx = 1e5 + 10;
using namespace std;
long long a[mx], b[mx];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, ans = 1, tmp = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] >= ans) {
      a[i] = ans;
      ans++;
    }
  }
  cout << ans;
}
