#include <bits/stdc++.h>
using namespace std;
const int N = 405, M = 2.5e5 + 7;
int a[N];
int s[M], t[M], r[M], f[M];
int solve(int i, long long V) {
  if (s[i] > t[i]) swap(s[i], t[i]);
  long long fuel = 0;
  int ans = 0;
  for (int j = s[i] + 1; j <= t[i]; j++) {
    long long cur = 1LL * f[i] * (a[j] - a[j - 1]);
    if (cur > V) return N;
    if (fuel + cur > V)
      ans++, fuel = cur;
    else
      fuel += cur;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> s[i] >> t[i] >> f[i] >> r[i];
  vector<int> truck;
  for (int i = 1; i <= m; i++) truck.push_back(i);
  mt19937 rng(9987665);
  shuffle(truck.begin(), truck.end(), rng);
  long long cur = 0;
  for (int i : truck) {
    if (solve(i, cur) <= r[i]) continue;
    long long lo = cur + 1, hi = 1e12;
    while (lo < hi) {
      long long m = (lo + hi) / 2;
      if (solve(i, m) <= r[i])
        hi = m;
      else
        lo = m + 1;
    }
    cur = lo;
  }
  cout << cur << endl;
}
