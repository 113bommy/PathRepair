#include <bits/stdc++.h>
using namespace std;
int LIM = 10;
vector<int> par;
vector<long long int> sum;
vector<int> _rank;
void make_set(int a, int v) {
  par[a] = a;
  sum[a] = v;
  _rank[a] = 0;
}
int find(int a) {
  if (a == par[a]) return a;
  return par[a] = find(par[a]);
}
void union_set(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (_rank[a] < _rank[b]) swap(a, b);
    par[b] = a;
    if (_rank[a] == _rank[b]) ++_rank[a];
    sum[a] += sum[b];
  }
}
bool check(int a, int b) { return find(a) == find(b); }
int main() {
  int n, v;
  cin >> n;
  par.resize(n);
  sum.resize(n);
  _rank.resize(n);
  vector<int> por(n);
  vector<long long int> ans(n + 1);
  vector<bool> flags(n);
  for (int i = 0; i < n; i++) {
    cin >> v;
    make_set(i, v);
  }
  for (int i = 0; i < n; i++) {
    cin >> por[i];
    --por[i];
  }
  long long int m = 0;
  for (int i = n - 1; i > 0; --i) {
    flags[por[i]] = true;
    if (por[i] < n - 1 && flags[por[i] + 1]) union_set(por[i], por[i + 1]);
    if (por[i] > 0 && flags[por[i] - 1]) union_set(por[i], por[i] - 1);
    m = max(m, sum[find(por[i])]);
    ans[i] = m;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
  return 0;
}
