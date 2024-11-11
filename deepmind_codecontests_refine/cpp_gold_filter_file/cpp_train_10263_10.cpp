#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 5;
void solve(long long ndx) {
  long long n;
  cin >> n;
  if (n < 3) {
    cout << 0;
    return;
  }
  long long a[MAX];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < a[n - 1] && a[i] > a[0]) ans++;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  long long ndx = 1;
  solve(ndx++);
  return 0;
}
