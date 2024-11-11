#include <bits/stdc++.h>
using namespace std;
long long int fastpow(long long int base, long long int exp, long long int M) {
  long long int res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % M;
    base = (base * base) % M;
    exp >>= 1;
  }
  return res;
}
vector<long long int> par;
long long int root(long long int a) {
  while (a != par[a]) {
    par[a] = par[par[a]];
    a = par[a];
  }
  return a;
}
void unio(long long int a, long long int b) { par[root(a)] = root(b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n + 1], b[n + 1];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  unordered_map<long long int, long long int> m;
  for (long long int i = 1; i <= n; ++i) {
    m[b[i]] = i;
  }
  vector<long long int> vis(n + 1);
  long long int i = 1;
  vector<vector<long long int> > ans;
  while (i != n) {
    if (!vis[i]) {
      long long int tp = i;
      vector<long long int> v;
      while (vis[tp] == 0) {
        vis[tp] = 1;
        v.push_back(tp);
        tp = m[a[tp]];
      }
      ans.push_back(v);
    }
    i++;
  }
  long long int sz = ans.size();
  cout << sz << endl;
  for (long long int i = 0; i <= sz - 1; ++i) {
    long long int tp = ans[i].size();
    cout << tp << " ";
    for (long long int j : ans[i]) cout << j << " ";
    cout << endl;
  }
  return 0;
}
