#include <bits/stdc++.h>
using namespace std;
string itosm(long long x) {
  if (x == 0) return "0";
  string res = "";
  while (x > 0) {
    res += ((x % 10) + '0');
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
long long stoim(string str) {
  long long res = 0;
  int p = 0;
  if (str[0] == '-') p++;
  for (int i = p; i < str.length(); i++) {
    res *= 10;
    res += (str[i] - '0');
  }
  return res;
}
const long long infll = 1e18 + 3;
const int inf = 1009000999;
const long double eps = 1e-7;
const int maxn = 1e6 + 1146;
const int baseint = 1000200013;
const long long basell = 1e18 + 3;
const long double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long binpow(long long x, long long st) {
  if (st == 0) return 1;
  if (st & 1) return binpow(x, st - 1) * x % mod;
  long long res = binpow(x, st >> 1);
  return res * res % mod;
}
long long fact[30], ans, n;
int cnt[30];
void rec(int x, int pos, int sum, vector<int> &v) {
  if (pos == 10) {
    if (sum != x) return;
    int cur = fact[x];
    for (int i = 0; i <= 9; i++) {
      cur /= fact[v[i]];
    }
    ans += cur;
    ans -= (cur * v[0]) / x;
  } else if (cnt[pos] > 0) {
    for (int i = 1; i <= cnt[pos]; i++) {
      if (sum + i <= x) {
        v.push_back(i);
        rec(x, pos + 1, sum + i, v);
        v.pop_back();
      }
    }
  } else {
    v.push_back(0);
    rec(x, pos + 1, sum, v);
    v.pop_back();
  }
}
void solve() {
  cin >> n;
  int l = 0;
  while (n > 0) {
    cnt[n % 10]++;
    n /= 10;
    l++;
  }
  fact[0] = 1;
  for (int i = 1; i <= 19; i++) {
    fact[i] = fact[i - 1] * i;
  }
  for (int i = 1; i <= l; i++) {
    vector<int> v;
    rec(i, 0, 0, v);
  }
  cout << ans;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
