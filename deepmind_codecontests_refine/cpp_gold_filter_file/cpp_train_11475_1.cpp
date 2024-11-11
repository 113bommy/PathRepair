#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool isPrime(long long a) {
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return (a != 1);
}
bool isPalindrom(const string& s, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (s[l + i] != s[r - i]) {
      return 0;
    }
  }
  return 1;
}
template <class type1>
type1 gcd(type1 a, type1 b) {
  type1 t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long positiveMod(long long v, long long md) {
  v = v % md;
  if (v < 0) {
    v += md;
  }
  return v;
}
vector<int> gr[2005];
vector<int> dat;
int sz[2005];
int root;
int res[2005];
int dfsSz(int v) {
  int k = 1;
  for (auto it : gr[v]) {
    k += dfsSz(it);
  }
  return sz[v] = k;
}
void getChilds(int v, vector<pair<int, int> >& inf) {
  inf.push_back({res[v], v});
  for (auto it : gr[v]) {
    getChilds(it, inf);
  }
}
void dfs(int v) {
  if (dat[v] + 1 > sz[v]) {
    cout << "NO\n";
    exit(0);
  }
  if (gr[v].empty()) {
    res[v] = 1;
    return;
  }
  for (auto it : gr[v]) {
    dfs(it);
  }
  vector<pair<int, int> > inf;
  for (auto it : gr[v]) {
    getChilds(it, inf);
  }
  sort(inf.begin(), inf.end());
  int i;
  for (i = 0; i < dat[v]; i++) {
    res[inf[i].second] = i + 1;
  }
  res[v] = dat[v] + 1;
  for (i = dat[v]; i < inf.size(); i++) {
    res[inf[i].second] = i + 2;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  dat.push_back(-1);
  int n, i, j, a, b, c;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a >> b;
    gr[a].push_back(i);
    dat.push_back(b);
  }
  root = gr[0][0];
  dfsSz(root);
  dfs(root);
  cout << "YES\n";
  for (i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
