#include <bits/stdc++.h>
using namespace std;
const long long N = 50005;
const long long mod = (1e9) + 7;
void solve() {
  int n, i, l, r, ans;
  cin >> n;
  vector<int> a(n + 1);
  int x, y, z;
  l = 1, r = 2;
  cout << "? " << l << " " << r << endl;
  cin >> x;
  l++, r++;
  cout << "? " << l << " " << r << endl;
  cin >> y;
  l = 1, r = 3;
  cout << "? " << l << " " << r << endl;
  cin >> z;
  a[2] = x + y - z;
  a[1] = x - a[2];
  a[3] = y - a[2];
  for (i = 4; i <= n; i++) {
    cout << "? " << i - 1 << " " << i << endl;
    cin >> x;
    a[i] = x - a[i - 1];
  }
  cout << "! ";
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  fflush(stdout);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
