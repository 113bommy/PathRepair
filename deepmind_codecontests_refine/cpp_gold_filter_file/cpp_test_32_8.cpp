#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[100005];
long long int mx[100005];
long long int sum[510];
long long int s[100005];
void create() {
  freopen("Codeforces.inp", "w", stdout);
  srand(time(NULL));
}
void pretest() {
  sum[0] = 0;
  for (int i = 1; i <= 500; i++) sum[i] = sum[i - 1] + i;
}
void Solve() {
  cin >> n;
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) cin >> a[n - i + 1];
  for (int i = 1; i <= n; i++) {
    mx[i] = a[i];
    if (i != 1) mx[i] = max(mx[i], mx[i - 1]);
    ;
    s[i] = a[i];
  }
  int res = 1;
  for (int i = 2; i <= sqrt(2 * n); i++) {
    int tmp = res;
    for (int j = n - i + 1; j >= sum[i - 1] + 1; j--) {
      s[j] += a[j + i - 1];
      if (s[j] < mx[j - 1]) {
        mx[j + i - 1] = s[j];
        res = i;
      } else
        mx[j + i - 1] = -1e16 + 7;
    }
    if (tmp == res) break;
    for (int j = sum[i] + 1; j <= n - i - 1; j++) {
      mx[j] = max(mx[j], mx[j - 1]);
      ;
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pretest();
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
