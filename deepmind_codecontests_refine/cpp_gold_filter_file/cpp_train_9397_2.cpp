#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 2e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
vector<pair<long long, long long> > X;
long long Solve(long long L, long long R) {
  if (L + 1 == R) return 0;
  int mid = (L + R) >> 1;
  assert(R - mid == mid - L);
  Solve(L, mid);
  Solve(mid, R);
  for (int i = L, j = mid; i < mid; i++, j++) X.push_back({i, j});
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n == 1) return cout << "0\n", 0;
  int p2 = 1;
  while (p2 + p2 < n) p2 += p2;
  Solve(1, p2 + 1);
  Solve(n + 1 - p2, n + 1);
  cout << X.size() << '\n';
  for (auto x : X) cout << x.first << ' ' << x.second << '\n';
  return 0;
}
