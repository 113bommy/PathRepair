#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int t, n, k;
int a_ind[maxn], b_ind[maxn];
vector<int> a, b;
int mul(int a, int b) { return 1ll * a * b % mod; }
int pwr(int a, int b) {
  if (!b) {
    return 1;
  }
  int res = pwr(a, b >> 1);
  res = mul(res, res);
  if (b & 1) {
    res = mul(res, a);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    a.clear(), b.clear();
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      a.push_back(num);
      a_ind[num] = i;
    }
    fill_n(b_ind, n, -2);
    for (int i = 0; i < k; i++) {
      int num;
      cin >> num;
      b.push_back(num);
      b_ind[num] = i;
    }
    int ans = 1;
    for (int i = 0; i < k; i++) {
      int tmp = 2;
      int s = b[i];
      if (!a_ind[s] || b_ind[a[a_ind[s] - 1]] > i) {
        tmp--;
      }
      if (a_ind[s] == n - 1 || b_ind[a[a_ind[s] + 1]] > i) {
        tmp--;
      }
      ans = mul(ans, tmp);
    }
    cout << ans << '\n';
  }
}
