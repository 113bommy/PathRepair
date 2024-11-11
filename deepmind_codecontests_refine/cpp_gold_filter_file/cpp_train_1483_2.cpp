#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(k), ans(k);
  for (int i = 0, ThxDem = k; i < ThxDem; ++i) cin >> a[i];
  for (int i = 0, ThxDem = k; i < ThxDem; ++i) {
    ans[i] = i + 1;
    if (i + a[i] > n) cout << "-1\n", exit(0);
  }
  long long need = n - (k + a.back() - 1);
  vector<long long> can(k);
  for (int i = 1, ThxDem = k; i < ThxDem; ++i)
    can[i] = (n - a[i] + 1) - (i + 1);
  for (int i = k - 2; i >= 0; i--) can[i] = min(can[i], can[i + 1]);
  long long add = 0;
  for (int i = 1, ThxDem = k; i < ThxDem; ++i) {
    long long now = a[i - 1] - 1;
    now = min(now, can[i] - add);
    now = min(now, need);
    need -= now;
    add += now;
    ans[i] += add;
  }
  if (ans.back() + a.back() - 1 != n) cout << "-1\n", exit(0);
  for (auto x : ans) cout << x << " ";
  cout << "\n";
}
