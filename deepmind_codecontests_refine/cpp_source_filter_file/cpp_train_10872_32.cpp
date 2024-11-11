#include <bits/stdc++.h>
using namespace std;
vector<int> construct(int n) {
  if (n == 1) return {1};
  if (n == 2) return {3, 4};
  if (n % 2 == 0) {
    vector<int> ret;
    for (int i = 0; i < n; i++) ret.push_back(i);
    ret.push_back((n - 2) / 2);
    return ret;
  }
  vector<int> ret;
  for (int i = 0; i < n - 2; i++) ret.push_back(1);
  ret.push_back(2);
  ret.push_back((n + 1) / 2);
  return ret;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> r = construct(n);
  vector<int> c = construct(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) cout << " ";
      cout << r[i] * c[j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
