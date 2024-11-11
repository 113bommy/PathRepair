#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long n, k, m, i, j = 0;
  map<long long, pair<long long, long long> > l;
  vector<long long> a;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> k;
    a.push_back(k);
  }
  for (i = 0; i < n; i++) {
    l[i + 1] = pair<long long, long long>(a[0], a[1]);
    if (a[0] > a[1]) {
      j = a[1];
      a.erase(a.begin() + 1);
      a.push_back(j);
    } else {
      j = a[0];
      a.erase(a.begin());
      a.push_back(j);
    }
  }
  for (i = 0; i < m; i++) {
    cin >> j;
    if (j <= n) {
      cout << l[j].first << " " << l[j].second << endl;
    } else {
      j -= n;
      j = j % (n - 1);
      cout << a[0] << " " << a[j + 1] << endl;
    }
  }
  return 0;
}
