#include <bits/stdc++.h>
using namespace std;
void fun() {}
long long int md = 998244353;
long long int __gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
long long int poww(long long int a, long long int b, long long int md) {
  if (b < 0) return 0;
  if (a == 0) return 0;
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (1ll * res * a) % md;
    }
    a = (1ll * a * a) % md;
    b >>= 1;
  }
  return res;
}
long long int poww(long long int a, long long int b) {
  if (b < 0) return 0;
  if (a == 0) return 0;
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (1ll * res * a);
    }
    a = (1ll * a * a);
    b >>= 1;
  }
  return res;
}
void ainp(long long int arr[], long long int n) {
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
}
void disp(long long int arr[], long long int n) {
  for (long long int i = 1; i <= n; i++) cout << arr[i] << " ";
  cout << "\n";
}
void dispv(vector<long long int> &v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
long long int divide(long long int a, long long int b, long long int md) {
  long long int rr = a * (poww(b, md - 2, md));
  rr %= md;
  return rr;
}
const long long int size = 5e5 + 5;
long long int n;
long long int nextt[size];
long long int p[size];
long long int val;
void dfs(long long int idx, vector<long long int> g[]) {
  p[idx] = val--;
  for (long long int child : g[idx]) dfs(child, g);
}
bool check() {
  long long int temp[n + 2];
  stack<long long int> stk;
  stk.push(n + 1);
  for (long long int i = n; i > 0; i--) {
    while (p[stk.top()] <= p[i]) stk.pop();
    temp[i] = stk.top();
    stk.push(i);
  }
  for (long long int i = 1; i <= n; i++)
    if (temp[i] != nextt[i]) return false;
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fun();
  long long int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int fg = 1;
    long long int maxi = 0;
    vector<long long int> g[n + 5];
    for (long long int i = 1; i <= n; i++) {
      cin >> nextt[i];
      if (nextt[i] == -1) nextt[i] = i + 1;
      g[nextt[i]].push_back(i);
      if (nextt[i] <= i) fg = 0;
      maxi = max(maxi, nextt[i]);
      if (nextt[i] == n + 1) maxi = 0;
    }
    if ((nextt[n] != n + 1) || fg == 0) {
      cout << "-1\n";
      continue;
    }
    for (long long int i = 1; i <= n + 1; i++) sort(g[i].begin(), g[i].end());
    val = n + 1;
    dfs(n + 1, g);
    if (!check()) {
      cout << "-1\n";
      continue;
    }
    for (long long int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
  }
  return 0;
}
