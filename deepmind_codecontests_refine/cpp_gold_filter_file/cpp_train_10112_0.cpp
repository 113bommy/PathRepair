#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long long int, long long int> mp1;
  long long int n, m, z = 1;
  cin >> n >> m;
  vector<long long int> v[m + 1];
  long long int a[m];
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    mp1[a[i]]++;
    v[mp1[a[i]]].push_back(a[i]);
    if (v[z].size() == n) {
      cout << 1;
      z++;
      continue;
    }
    cout << 0;
  }
  return 0;
}
