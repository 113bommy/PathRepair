#include <bits/stdc++.h>
using namespace std;
int const N = int(1e5) + 5;
int const mod = int(1e9) + 7;
int x[N], y[N];
int mark[N];
map<int, int> kx, ky;
vector<int> ind;
vector<int> gr[N];
bool cmpx(int i, int j) {
  if (x[i] == x[j]) {
    return y[i] < y[j];
  }
  return x[i] < x[j];
}
bool cmpy(int i, int j) {
  if (y[i] == y[j]) {
    return x[i] < x[j];
  }
  return y[i] < y[j];
}
long long pow(long long a, int deg) {
  long long result = 1;
  while (deg > 0) {
    if (deg & 1) {
      result *= a;
      result %= mod;
    }
    a *= a;
    a %= mod;
    deg >>= 1;
  }
  return result;
}
bool dfs(int v, int &cnt, int p = -1) {
  mark[v] = 1;
  if (kx[x[v]] == 0) {
    ++kx[x[v]];
    ++cnt;
  }
  if (ky[y[v]] == 0) {
    ++ky[y[v]];
    ++cnt;
  }
  bool flag = false;
  for (int i = 0; i < gr[v].size(); ++i) {
    int u = gr[v][i];
    if (mark[u] && u != p) {
      flag = true;
    }
    if (!mark[u]) {
      flag |= dfs(u, cnt, v);
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(false);
  ifstream in("input.txt");
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    ind.push_back(i);
  }
  sort(ind.begin(), ind.end(), cmpx);
  for (int i = 1; i < n; ++i) {
    if (x[ind[i - 1]] == x[ind[i]]) {
      gr[ind[i - 1]].push_back(ind[i]);
      gr[ind[i]].push_back(ind[i - 1]);
    }
  }
  sort(ind.begin(), ind.end(), cmpy);
  for (int i = 1; i < n; ++i) {
    if (y[ind[i - 1]] == y[ind[i]]) {
      gr[ind[i - 1]].push_back(ind[i]);
      gr[ind[i]].push_back(ind[i - 1]);
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    if (!mark[i]) {
      int cnt = 0;
      if (dfs(i, cnt)) {
        ans *= pow(2, cnt);
      } else {
        long long mult = (pow(2, cnt) - 1);
        mult %= mod;
        ans *= mult;
      }
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
