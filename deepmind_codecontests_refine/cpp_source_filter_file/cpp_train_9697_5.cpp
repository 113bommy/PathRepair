#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int mod = 998244353;
const int maxn = (int)2e5 + 5;
const int LOGN = 20;
int diff[maxn], same[maxn], pK_1[maxn];
int k;
vector<int> arr[2];
int solve(int idx) {
  int n = arr[idx].size();
  int ret = 1;
  for (int r = 0; r < (n); r++) {
    if (arr[idx][r] != -1) continue;
    int l = r;
    while (r + 1 < n && arr[idx][r + 1] == -1) ++r;
    int len = r - l + 1;
    if (l == 0 && r == n - 1)
      ret = k * 1LL * pK_1[len - 1] % mod;
    else if (l == 0 || r == n - 1)
      ret = ret * 1LL * pK_1[len] % mod;
    else if (arr[idx][l - 1] == arr[idx][r + 1])
      ret = ret * 1LL * same[len] % mod;
    else
      ret = ret * 1LL * diff[len] % mod;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x;
  cin >> n >> k;
  pK_1[0] = 1;
  same[1] = k - 1, diff[1] = k - 2;
  for (int i = 1; i <= (n); i++) {
    cin >> x;
    if (x != -1 && arr[i & 1].size() > 0 && arr[i & 1].back() == x) {
      cout << "0";
      return 0;
    }
    arr[i & 1].push_back(x);
    pK_1[i] = pK_1[i - 1] * 1LL * (k - 1) % mod;
    if (i > 1) {
      same[i] = diff[i - 1] * 1LL * (k - 2) % mod;
      diff[i] = (diff[i - 1] * 1LL * (k - 2) % mod + same[i - 1]) % mod;
    }
  }
  cout << solve(0) * 1LL * solve(1) % mod;
  return 0;
}
