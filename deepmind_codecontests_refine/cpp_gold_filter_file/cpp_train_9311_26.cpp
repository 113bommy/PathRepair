#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const long long MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<long long> vect(n);
  for (int i = 0; i < n; i++) cin >> vect[i];
  vector<long long> l(n, 1), r(n, 1);
  for (int i = 1; i < n; i++)
    if (vect[i] > vect[i - 1]) l[i] = l[i - 1] + 1;
  for (int i = n - 2; i >= 0; i--)
    if (vect[i] < vect[i + 1]) r[i] = r[i + 1] + 1;
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    if (i != 0) ans = max(ans, l[i - 1] + 1);
    if (i != n - 1) ans = max(ans, 1 + r[i + 1]);
    if (i != 0 && i != n - 1 && vect[i - 1] + 1 < vect[i + 1]) {
      ans = max(ans, l[i - 1] + 1 + r[i + 1]);
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
