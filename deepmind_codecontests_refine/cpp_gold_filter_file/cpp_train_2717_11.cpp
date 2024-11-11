#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long INF = 1e18 + 7;
long long n, a[N], f[N][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) cout << a[1], exit(0);
  long long minn = INF;
  for (long long i = 1; i <= n; i++) minn = min(minn, abs(a[i]));
  f[0][0] = f[0][1] = 0;
  for (long long i = 1; i <= n; i++) {
    f[i][0] = max(f[i - 1][0], f[i - 1][1]) - a[i];
    f[i][1] = max(f[i - 1][0], f[i - 1][1]) + a[i];
  }
  long long s = 0;
  for (long long i = 1; i <= n; i++) s += abs(a[i]);
  bool check = false;
  for (long long i = 1; i <= n; i++)
    if (a[i] >= 0) check = true;
  if (check == false) cout << s - 2 * minn, exit(0);
  check = false;
  for (long long i = 1; i <= n; i++)
    if (a[i] <= 0) check = true;
  if (check == false) cout << s - 2 * minn, exit(0);
  cout << s;
  return 0;
}
