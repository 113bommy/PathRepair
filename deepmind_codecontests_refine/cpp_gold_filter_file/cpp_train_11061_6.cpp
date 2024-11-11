#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n;
  cin >> n;
  long long int a[n], b[n], i, maxs = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  map<pair<long long int, long long int>, long long int> m;
  long long int i1[n], i2[n];
  for (i = 0; i < n; i++) i1[a[i]] = i;
  for (i = 0; i < n; i++) i2[b[i]] = i;
  for (i = 0; i < n; i++) {
    if (i2[b[i]] > i1[b[i]])
      m[{i2[b[i]] - i1[b[i]], n - (i2[b[i]] - i1[b[i]])}]++;
    else
      m[{n - (i1[b[i]] - i2[b[i]]), i1[b[i]] - i2[b[i]]}]++;
  }
  for (auto x : m) maxs = max(x.second, maxs);
  cout << maxs << endl;
}
