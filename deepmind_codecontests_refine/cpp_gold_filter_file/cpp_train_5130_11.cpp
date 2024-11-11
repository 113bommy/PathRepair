#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int N = 5e3 + 10;
const long long inf = 0x3f3f3f3f;
const long long oo = 8e18;
const int dir[][2] = {{0, 1}, {1, 0},  {0, -1}, {-1, 0},
                      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
long long cnt[50][2];
void solve(vector<int> v, int p) {
  if (v.empty() || p < 0) return;
  vector<int> a, b;
  for (auto i : v) {
    if (i >> p & 1)
      a.push_back(i), cnt[p][1] += b.size();
    else
      b.push_back(i), cnt[p][0] += a.size();
  }
  solve(a, p - 1);
  solve(b, p - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  solve(v, 30);
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i <= 30; i++) {
    if (cnt[i][1] < cnt[i][0])
      ans2 += 1 << i, ans1 += cnt[i][1];
    else
      ans1 += cnt[i][0];
  }
  cout << ans1 << ' ' << ans2 << '\n';
  return 0;
}
