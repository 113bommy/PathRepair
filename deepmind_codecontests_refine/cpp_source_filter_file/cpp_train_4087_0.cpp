#include <bits/stdc++.h>
using namespace std;
const long long int MOD = (long long int)1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b = b >> 1;
  }
  return res % MOD;
}
vector<vector<long long int> > G;
void solve(long long int testnum) {
  long long int n, m;
  cin >> n >> m;
  G.resize(n + 1);
  vector<long long int> tt(n + 1, 0);
  for (long long int i = 0; i < m; i++) {
    long long int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<pair<long long int, long long int> > bc;
  for (long long int i = 1; i <= n; i++) {
    long long int temp;
    cin >> temp;
    bc.push_back(make_pair(temp, i));
  }
  sort(bc.begin(), bc.end());
  long long int check = 0;
  for (long long int i = 0; i < bc.size(); i++) {
    tt[bc[i].second] = bc[i].first;
    vector<long long int> naap;
    for (long long int j = 0; j < G[bc[i].second].size(); j++) {
      naap.push_back(tt[G[bc[i].second][j]]);
    }
    if (naap.size() == 0) {
      if (bc[i].second != 1) {
        check = 1;
      }
      continue;
    }
    sort(naap.begin(), naap.end());
    for (long long int k = 0; k < naap.size(); k++) {
      long long int temp = naap[k];
      if (k > 0) {
        temp -= naap[k - 1];
      }
      if (temp > 1) {
        check = 1;
      }
    }
    if (naap[naap.size() - 1] != bc[i].first - 1) {
      check = 1;
    }
  }
  if (check == 1) {
    cout << "-1\n";
    return;
  }
  for (long long int i = 0; i < n; i++) {
    cout << bc[i].second << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
}
