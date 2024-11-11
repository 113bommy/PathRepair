#include <bits/stdc++.h>
using namespace std;
void solve(int testcase) {
  long long i = 0, j = 0;
  int n, curr, k;
  cin >> n >> curr >> k;
  int a[n + 1];
  for (i = 0; i < n; i++) cin >> a[i + 1];
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] >= a[i + 1])
      curr += min(a[i] - (a[i + 1] - k), a[i]);
    else {
      if (a[i + 1] - a[i] <= k)
        curr += (k - (a[i + 1] - a[i]));
      else if (((a[i + 1] - a[i]) - k) > curr) {
        cout << "NO\n";
        return;
      } else
        curr -= ((a[i + 1] - a[i]) - k);
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
