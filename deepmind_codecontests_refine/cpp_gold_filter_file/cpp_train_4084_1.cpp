#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int A = numeric_limits<int>::max();
int n;
int a[N];
int pref[N], suff[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pref[0] = A;
  suff[n + 1] = A;
  for (int i = 1; i <= n; i++) pref[i] = (pref[i - 1] & (a[i] ^ A));
  for (int i = n; i >= 1; i--) suff[i] = (suff[i + 1] & (a[i] ^ A));
  int ans = -A, pos = -A;
  for (int i = 1; i <= n; i++) {
    int res = pref[i - 1] & a[i] & suff[i + 1];
    if (res > ans) {
      ans = res;
      pos = i;
    }
  }
  assert(pos >= 1);
  cout << a[pos] << ' ';
  for (int i = 1; i <= n; i++)
    if (i != pos) cout << a[i] << ' ';
  return 0;
}
