#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111;
int n, m, k, p[MAXN], invp[MAXN], x, sol;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> p[i];
    invp[p[i]] = i;
  }
  for (int i = 1; i <= k; i++) v.push_back(p[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      auto it = find(v.begin(), v.end(), x);
      sol += it - v.begin() + 1;
      v.erase(it);
      v.insert(v.begin(), x);
    }
  }
  cout << sol << endl;
}
