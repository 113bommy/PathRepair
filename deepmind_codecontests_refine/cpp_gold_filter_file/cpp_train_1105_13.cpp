#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)2e18;
const string name = "c";
const int NMAX = 100010;
int n, ans[NMAX], step[NMAX], used[1000];
void solve(int n) {
  step[n] = n + 1;
  memset(used, 0, sizeof(used));
  for (int i = 2; i * (i + 1) <= 2 * n; ++i)
    if ((n - i * (i + 1) / 2) % i == 0) {
      int now = 0, zn = 1 + (n - i * (i + 1) / 2) / i;
      for (int j = 0; j < (int)i; j++) now ^= ans[zn + j];
      if (now < 1000) used[now] = 1;
      if (now == 0) step[n] = min(step[n], i);
    }
  for (int i = 0; i < (int)1000; i++)
    if (!used[i]) {
      ans[n] = i;
      break;
    }
}
int main() {
  cin >> n;
  ans[0] = ans[1] = ans[2];
  step[0] = 1, step[1] = 2, step[2] = 3;
  for (int i = 3; i <= n; ++i) solve(i);
  if (step[n] == n + 1)
    cout << -1 << endl;
  else
    cout << step[n] << endl;
  return 0;
}
