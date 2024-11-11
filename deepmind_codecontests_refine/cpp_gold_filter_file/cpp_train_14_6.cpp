#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
const long double EPS = 1e-9;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long n, m, k;
long long q;
vector<vector<long long>> vec;
vector<bool> used;
vector<long long> cnt;
vector<long long> ans;
vector<long long> pref;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vec.resize(n);
  cnt.resize(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    int v, to;
    cin >> v >> to;
    --v;
    --to;
    vec[v].push_back(to);
    vec[to].push_back(v);
    cnt[v]++;
    cnt[to]++;
  }
  int cntl = 0, cntnl = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 1)
      cntl++;
    else if (cnt[i] == 2) {
      cout << "NO";
      return 0;
    } else {
      int cntal = 0;
      for (int j = 0; j < vec[i].size(); ++j) {
        if (cnt[vec[i][j]] == 1) {
          cntal++;
        }
      }
      if (cntal <= 1) {
        cntnl++;
      }
    }
  }
  if ((cntl == 2 && n > 2)) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
