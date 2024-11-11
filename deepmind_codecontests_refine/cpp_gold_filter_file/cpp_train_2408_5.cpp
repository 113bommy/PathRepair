#include <bits/stdc++.h>
using namespace std;
long long arr[200005];
int par[200005];
int fi(int x) {
  if (par[x] == -1)
    return x;
  else {
    par[x] = fi(par[x]);
    return par[x];
  }
}
bool un(int a, int b) {
  int x = fi(a);
  int y = fi(b);
  if (x == y) {
    return false;
  } else {
    par[x] = y;
    return true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  long long x = 1e15;
  int ind = -1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    par[i] = -1;
    if (arr[i] < x) {
      x = arr[i];
      ind = i;
    }
  }
  vector<pair<long long, pair<int, int> > > edge(0);
  for (int i = 1; i <= m; i++) {
    long long a, b, w;
    cin >> a >> b >> w;
    edge.push_back(make_pair(w, make_pair(a, b)));
  }
  for (int i = 1; i <= n; i++) {
    if (i == ind)
      continue;
    else {
      edge.push_back(make_pair(arr[ind] + arr[i], make_pair(i, ind)));
    }
  }
  int cou = 0;
  sort(edge.begin(), edge.end());
  int i = 0;
  long long sum = 0;
  while (cou != n - 1) {
    bool valid = un(edge[i].second.first, edge[i].second.second);
    if (valid) {
      sum += edge[i].first;
      cou++;
    }
    i++;
  }
  cout << sum << '\n';
}
