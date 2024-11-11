#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int mul(int a, int b) { return ((long long int)a * b) % mod; }
int pow(int a) {
  if (!a) return 1;
  int ret = pow(a / 2), ans = mul(ret, ret);
  if (a & 1) return mul(ans, 2);
  return ans;
}
int po3(int a) { return (a * a * a); }
long long int check(long long int n, long long int mid,
                    vector<long long int> arr) {
  long long int cnt = 0;
  for (auto &i : arr) {
    if (i <= mid) {
      cnt += mid / i;
      if (cnt > n) return 1;
    } else
      break;
  }
  if (cnt == n) return 2;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string x;
  cin >> x;
  long long int ans = 1, m = 1e9 + 7, i, n = x.size();
  for (i = 0; i < n; ++i) {
    long long int a = x[i] - '0', j = 1;
    while (x[i + j] == '0' + 9 - a) {
      a = 9 - a;
      j++;
    }
    i += j - 1;
    if (j & 1) ans = (ans * (j / 2 + 1));
  }
  cout << ans << endl;
  return 0;
}
