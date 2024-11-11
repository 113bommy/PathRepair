#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int n;
std::vector<bool> vis(101 + 1, 0);
void dfs(long long int ind, long long int curr) {
  vis[ind] = true;
  for (long long int i = ind + 1; i < n; i++) {
    if (!vis[i]) {
      if (v[i] >= curr) {
        curr++;
        dfs(i, curr);
        return;
      }
    }
  }
}
void solve() {
  cin >> n;
  for (long long int i = 0; i < (n); i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  long long int c = 0;
  long long int curr = 0;
  for (long long int i = 0; i < (n); i++) {
    if (!vis[i]) {
      dfs(i, 1);
      c++;
    }
  }
  cout << c << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  solve();
  return 0;
}
