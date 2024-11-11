#include <bits/stdc++.h>
using namespace std;
int ind[100001];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int x;
  vector<int> v, vv;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ind[x] = i + 1;
    vv.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    v.push_back(x);
  }
  int c = 0;
  for (int i = 0; i < m; i++) {
    c += (ind[v[i]] / k);
    if (ind[v[i]] % k) c++;
    if (ind[v[i]] > 1) {
      x = vv[ind[v[i]] - 2];
      swap(vv[ind[v[i]] - 2], vv[ind[v[i]] - 1]);
      ind[x]++;
      ind[v[i]]--;
    }
  }
  cout << c << "\n";
}
