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
const long long mod = 1e9 + 9;
int p[maxn];
int c[maxn];
long long ans[maxn];
pair<int, pair<int, int> > f[maxn];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) f[i] = make_pair(p[i], make_pair(c[i], i));
  sort(f, f + n);
  vector<int> a;
  for (int i = 0; i < n; i++) {
    ans[f[i].second.second] += f[i].second.first;
    for (int x : a) ans[f[i].second.second] += x;
    a.push_back(f[i].second.first);
    sort(a.rbegin(), a.rend());
    if (a.size() > k) a.pop_back();
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
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
