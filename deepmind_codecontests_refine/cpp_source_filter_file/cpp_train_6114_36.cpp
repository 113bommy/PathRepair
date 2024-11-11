#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i;
  cin >> n >> m;
  long long int x[n + 1];
  long long int y[n + 1];
  map<long long int, long long int> mp;
  for (i = 0; i < n; i++) cin >> x[i];
  vector<long long int> v;
  for (i = 0; i < m; i++) {
    cin >> y[i];
    mp[y[i]]++;
  }
  for (i = 0; i < n; i++) {
    if (mp[x[i]] > 0) v.push_back(x[i]);
  }
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
}
