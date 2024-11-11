#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 9;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, x, y;
  cin >> n >> m;
  map<pair<long long, long long>, long long> mm;
  long long arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    mm[make_pair(x, y)] = 1;
    mm[make_pair(y, x)] = 1;
  }
  long long mn = 10e8;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (mm[make_pair(i, j)] && mm[make_pair(i, k)] && mm[make_pair(j, k)]) {
          if (mn > arr[i] + arr[j] + arr[k]) mn = arr[i] + arr[j] + arr[k];
        }
      }
    }
  }
  if (mn != 10e8)
    cout << mn;
  else
    cout << -1;
  return 0;
}
