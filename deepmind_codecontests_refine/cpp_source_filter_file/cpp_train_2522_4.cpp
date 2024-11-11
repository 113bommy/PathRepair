#include <bits/stdc++.h>
using namespace std;
long long POW(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b == 1) return a % mod;
  long long y = POW(a, b / 2, mod);
  if (b % 2 == 0)
    return (y * y) % mod;
  else
    return (((y * y) % mod) * a) % mod;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
const long long MOD = 1000000007;
const long long SIZE = 1000001;
const int INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
const long long MAXN = numeric_limits<long long>::max();
const long long MAX = 90000000;
vector<long long> solve(vector<long long> v) {
  int n = v.size();
  vector<long long> x(n + 1);
  int i = 0;
  while (i < n) {
    if (v[i] == 0)
      i++;
    else {
      int j = i;
      while (j < n && v[j] == 1) j++;
      for (int k = 1; k <= j - i; k++) x[k] += j - i - k + 1;
      i = j;
    }
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  vector<long long> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  vector<long long> x = solve(a);
  vector<long long> y = solve(b);
  int c = 0;
  for (int i = 1; i < x.size(); i++) {
    if (k % i == 0 && k / i <= m) c += x[i] * y[k / i];
  }
  cout << c;
}
