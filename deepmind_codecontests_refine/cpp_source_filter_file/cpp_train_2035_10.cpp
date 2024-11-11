#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7, N = 1e4 + 20;
vector<int> gr[N];
int n, i, j;
long long f(int a) {
  int cou0 = 1;
  int cou2 = 1;
  return a * (a - 1) / 2;
}
long long ans;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int u = 1; u <= n - 1; u++) {
    cin >> i >> j;
    gr[i].push_back(j);
    gr[j].push_back(i);
  }
  for (int u = 1; u <= n - 1; u++) {
    if (gr[u].size() >= 2) {
      ans += f(gr[u].size());
    }
  }
  cout << ans;
}
