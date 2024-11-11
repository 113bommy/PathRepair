#include <bits/stdc++.h>
using namespace std;
long long sz[300009], par[300009];
long long res;
long long n, k;
std::vector<long long> pos[300009];
long long getparent(long long x) {
  if (par[x] == x) return x;
  return par[x] = getparent(par[x]);
}
void merge(long long x, long long y) {
  long long p1 = getparent(x);
  long long p2 = getparent(y);
  if (p1 == p2) return;
  par[p1] = p2;
  res -= min(sz[p1], sz[p1 ^ 1]);
  res -= min(sz[p2], sz[p2 ^ 1]);
  sz[p2] += sz[p1];
  res += min(sz[p2], sz[p2 ^ 1]);
  sz[p1] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  string x;
  cin >> x;
  for (long long int i = 0; i < 2 * k + 2; i++) {
    par[i] = i;
    sz[i] = (i) % 2;
  }
  for (long long int i = 0; i < k; i++) {
    long long ss;
    cin >> ss;
    for (long long int j = 0; j < ss; j++) {
      long long yy;
      cin >> yy;
      yy--;
      pos[yy].push_back(i);
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (pos[i].size() == 0) {
      cout << res << '\n';
      continue;
    }
    if (pos[i].size() == 1) {
      if (x[i] == '1') {
        long long pp = getparent(2 * pos[i][0] + 1);
        res -= min(sz[pp], sz[pp ^ 1]);
        sz[pp] = 1e18;
        res += sz[pp ^ 1];
      } else {
        long long pp = getparent(2 * pos[i][0]);
        res -= min(sz[pp], sz[pp ^ 1]);
        sz[pp] = 1e7;
        res += sz[pp ^ 1];
      }
      cout << res << '\n';
      continue;
    }
    if (x[i] == '1') {
      merge(2 * pos[i][0], 2 * pos[i][1]);
      merge((2 * pos[i][0]) + 1, (2 * pos[i][1]) + 1);
    } else {
      merge(2 * pos[i][0], (2 * pos[i][1]) + 1);
      merge((2 * pos[i][0]) + 1, 2 * pos[i][1]);
    }
    cout << res << '\n';
  }
}
