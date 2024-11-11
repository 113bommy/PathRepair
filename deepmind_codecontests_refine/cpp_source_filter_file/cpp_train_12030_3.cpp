#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, q;
  cin >> n >> q;
  vector<long long int> v;
  map<long long int, set<long long int>> M;
  long long int un = 0, mx = 0;
  for (long long int i = 0; i <= q - 1; i++) {
    long long int t, x;
    cin >> t >> x;
    if (t == 1) {
      M[x].insert(i);
      v.push_back(x);
      un++;
    } else if (t == 2) {
      un -= M[x].size();
      M[x].clear();
    } else if (t == 3) {
      if (mx < x) {
        for (long long int j = mx + 1; j <= x; j++) {
          if (M[v[j - 1]].find(j - 1) != M[v[j - 1]].end()) {
            M[v[j - 1]].erase(j - 1);
            un--;
          }
        }
        mx = x;
      }
    }
    cout << un << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
