#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a.begin(), a.end());
  long long mm = a[n / 2];
  for (int i = n / 2; i < n - 1; i++) {
    long long r = a[i + 1] - a[i];
    if (k >= r * (i - n / 2 + 1))
      k -= r * (i - n / 2 + 1);
    else if (k > 0) {
      mm += k / (i - n / 2 + 1);
      k = 0;
      break;
    } else
      break;
    mm = a[i + 1];
  }
  if (k > 0) mm += k / (n / 2 + 1);
  cout << mm << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
