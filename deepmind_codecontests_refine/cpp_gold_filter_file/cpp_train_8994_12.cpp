#include <bits/stdc++.h>
using namespace std;
void init() {
  long long n, m, k;
  cin >> n >> m;
  if (m == 0) {
    cout << "YES" << endl;
    return;
  }
  vector<long long> a(m);
  for (long long i = 0; i < m; i++) cin >> a[i];
  sort(a.begin(), a.end());
  bool ok = true;
  if (a[0] == 1 or a[m - 1] == n) ok = false;
  for (long long i = 0; i < m - 2; i++) {
    if (a[i] + 1 == a[i + 1] and a[i] + 2 == a[i + 2]) {
      ok = false;
      break;
    }
  }
  if (ok == true)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  init();
  return 0;
}
