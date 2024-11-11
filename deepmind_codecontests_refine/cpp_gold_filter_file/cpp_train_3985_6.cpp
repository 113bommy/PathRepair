#include <bits/stdc++.h>
using namespace std;
void initialize(int gp[], int n) {
  for (int j = 1; j < n; j++) {
    gp[j] = j;
  }
  return;
}
int root(int gp[], int x) {
  while (gp[x] != x) {
    gp[x] = gp[gp[x]];
    x = gp[x];
  }
  return x;
}
void union2(int gp[], int x, int y) {
  int p = root(gp, x);
  int q = root(gp, y);
  gp[p] = gp[q];
}
long long int mst(int gp[], int n, vector<pair<int, pair<int, int> > > v) {
  long long int cost, mincost = 0, x, y, w;
  pair<int, int> x1;
  for (int j = 0; j < n; j++) {
    x1 = v[j].second;
    x = x1.first;
    y = x1.second;
    w = v[j].first;
    if (root(gp, x) != root(gp, y)) {
      mincost += w;
      union2(gp, x, y);
    }
  }
  return (mincost);
}
int main() {
  const int N = 2e5 + 10;
  long long int n, m, ans = 0;
  cin >> n >> m;
  int gp[N];
  initialize(gp, N + 1);
  vector<pair<int, pair<int, int> > > v;
  int arr[n], brr[m];
  for (int j = 0; j < n; j++) {
    cin >> arr[j];
  }
  for (int j = 0; j < m; j++) {
    cin >> brr[j];
  }
  for (int j = 0; j < n; j++) {
    int n1;
    cin >> n1;
    for (int k = 0; k < n1; k++) {
      int w, w1;
      cin >> w1;
      w1 = w1 - 1;
      w = arr[j] + brr[w1];
      ans += w;
      w = -w;
      v.push_back(make_pair(w, make_pair(j, n + w1)));
    }
  }
  sort(v.begin(), v.end());
  int sz = v.size();
  cout << ans + mst(gp, sz, v) << "\n";
}
