#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5, mod = 1e9 + 7;
const long long mod2 = 1ll * mod * mod;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
vector<vector<int> > mul(vector<vector<int> > &a, vector<vector<int> > &b) {
  int n = a.size(), k = a[0].size();
  int k2 = b.size(), m = b[0].size();
  assert(k == k2);
  vector<vector<int> > ret(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long tmp = 0;
      for (int k = 0; k < k2; k++) {
        tmp += (1ll * a[i][k] * b[k][j]);
        while (tmp >= mod2) tmp -= mod2;
      }
      ret[i][j] = tmp % mod;
    }
  }
  return ret;
}
vector<vector<int> > I(int n) {
  vector<vector<int> > ret(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}
vector<vector<int> > fp(vector<vector<int> > &b, long long p) {
  if (p == 0) return I(b.size());
  auto ret = fp(b, p >> 1);
  ret = mul(ret, ret);
  if (p & 1) ret = mul(ret, b);
  return ret;
}
int calc(char a) {
  if (a >= 'a' && a <= 'z') return a - 'a';
  return a - 'A' + 26;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  int m, k;
  cin >> n >> m >> k;
  vector<vector<int> > t(m, vector<int>(m, 1));
  vector<vector<int> > f(m, vector<int>(1, 1));
  while (k--) {
    char a, b;
    cin >> a >> b;
    t[calc(a)][calc(b)] = 0;
  }
  auto exp = fp(t, n - 1);
  auto ans = mul(exp, f);
  int res = 0;
  for (int i = 0; i < m; i++) res = add(res, ans[i][0]);
  cout << res;
  return 0;
}
