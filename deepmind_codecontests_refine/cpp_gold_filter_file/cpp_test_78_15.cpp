#include <bits/stdc++.h>
using namespace std;
long long int dfs(int i, int j, vector<vector<long long int>>& mt,
                  vector<vector<bool>>& vis) {
  int n = mt.size(), m = mt[0].size();
  if (i < 0 || i >= mt.size() || j < 0 || j >= mt[0].size()) return 0;
  vis[i][j] = true;
  int c = 1;
  for (int k = max(0, i - 1); k <= min(n - 1, i + 1); k++) {
    for (int kk = max(0, j - 1); kk <= min(m - 1, j + 1); kk++) {
      if (vis[k][kk] == false && mt[i][j] == mt[k][kk]) {
        c = dfs(k, kk, mt, vis) + 1;
      }
    }
  }
  return c;
}
void fac(long long int x, vector<long long int>& v) {
  bitset<32> b(x);
  for (int i = 0; i < 32; i++) {
    if (b[i] == 1) v[i]++;
  }
}
void fact(long long int k, vector<long long int>& di) {
  for (long long int i = 1; i <= sqrt(k); i++) {
    if (k % i == 0) {
      di.push_back(i);
      if (i != k / i) di.push_back(k / i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(32, 0);
    vector<long long int> in;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      if (x != 0) in.push_back(x);
      fac(x, v);
    }
    long long int mi = n + 1;
    for (int i = 0; i < 32; i++) {
      if (v[i] != 0) {
        mi = min(mi, v[i]);
      }
    }
    if (mi == n + 1) {
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
    } else {
      vector<long long int> di;
      fact(mi, di);
      vector<long long int> fmo(32, 0);
      for (auto x : in) {
        int k = log2(x);
        fmo[k]++;
      }
      vector<long long int> ans;
      for (auto x : di) {
        bool ok = true;
        for (int i = 0; i < 32; i++) {
          if (v[i] != 0 && v[i] % x != 0) {
            ok = false;
          }
        }
        if (ok) ans.push_back(x);
      }
      sort(ans.begin(), ans.end());
      for (auto x : ans) cout << x << " ";
    }
    cout << endl;
  }
}
