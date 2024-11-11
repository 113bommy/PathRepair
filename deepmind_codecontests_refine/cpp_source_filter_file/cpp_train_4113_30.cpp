#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const long long INF = 1e12;
const int N = 401;
int res[N], n, a;
vector<pair<int, pair<long long, long long> > > arr;
int main() {
  cin >> n;
  for (int i = 2; i <= n * 2; i++) {
    for (int j = 1; j < i; j++) {
      cin >> a;
      arr.push_back(make_pair(a, make_pair(i, j)));
    }
  }
  sort(arr.rbegin(), arr.rend());
  for (int i = 0; i < arr.size(); i++) {
    int u = arr[i].second.first;
    int v = arr[i].second.second;
    if (res[u] || res[v]) continue;
    res[u] = v;
    res[v] = u;
  }
  for (int i = 1; i <= 2 * n; i++) cout << res[i] << " ";
}
