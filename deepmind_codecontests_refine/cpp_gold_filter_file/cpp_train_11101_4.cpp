#include <bits/stdc++.h>
using namespace std;
vector<int> g[222];
vector<int> get(int n, vector<int> &a, vector<int> &b) {
  vector<int> res(n, 0);
  for (int i = 1; i < n; i++) res[i] = a[i - 1];
  for (int i = 0; i < (int)(b.size()); i++) res[i] += b[i];
  for (int i = 0; i < n; i++) res[i] = res[i] % 2;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  g[0] = {1};
  g[1] = {0, 1};
  for (int i = 2; i < 151; i++) g[i] = get(i + 1, g[i - 1], g[i - 2]);
  int n;
  cin >> n;
  cout << (int)(g[n].size()) - 1 << '\n';
  for (int e : g[n]) cout << e << " ";
  cout << '\n';
  cout << (int)(g[n - 1].size()) - 1 << '\n';
  for (int e : g[n - 1]) cout << e << " ";
  cout << '\n';
  return 0;
}
