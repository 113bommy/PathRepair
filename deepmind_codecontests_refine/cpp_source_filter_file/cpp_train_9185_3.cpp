#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void prl(int x) { cout << x << "\n"; }
int cbrt(int x) {
  int lo = 1, hi = min(2000000ll, x);
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int N = (int)(5 * 1e5 + 10);
int pre[N];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 2 * k + 10; i++) pre[i] = 0;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n / 2; i++)
      vec.emplace_back(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1]));
    map<int, int> mp;
    for (auto it : vec) {
      int l = it.first + 1;
      int r = it.second + k;
      mp[it.first + it.second]++;
      pre[l] += 1;
      pre[r + 1] -= 1;
    }
    int sum = 0;
    for (int i = 0; i < 2 * k + 10; i++) {
      sum += pre[i];
      pre[i] = sum;
    }
    int mini = n;
    for (int i = 2; i <= 2 * k; i++) {
      int cnt0 = mp[i];
      int cnt1 = (pre[i] - cnt0);
      int cnt2 = (n / 2) - (cnt1)-cnt0;
      int cnt = cnt + (cnt2 * 2);
      mini = min(cnt, mini);
    }
    prl(mini);
  }
}
