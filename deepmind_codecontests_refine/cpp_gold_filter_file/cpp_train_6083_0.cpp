#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e14;
long long int mod = 1e9 + 7;
char en = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p;
    cin >> n >> p;
    vector<pair<long long int, long long int> > edges;
    map<pair<long long int, long long int>, long long int> par;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = i + 1; j <= n; j++) par[{i, j}];
    }
    for (long long int i = 2; i <= n; i++) {
      edges.push_back({1, i});
      if (i != n)
        edges.push_back({i, i + 1});
      else
        edges.push_back({2, n});
    }
    edges.push_back({2, 4});
    edges.push_back({3, 5});
    for (pair<long long int, long long int> x : edges) par.erase(x);
    while (p--) {
      edges.push_back(par.begin()->first);
      par.erase(par.begin());
    }
    for (pair<long long int, long long int> x : edges)
      cout << x.first << " " << x.second << endl;
  }
  return 0;
}
