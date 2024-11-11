#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
long long int inf = 1e18;
long long int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, t, k, x, y, z, N;
  cin >> n;
  long long int a[n];
  map<long long int, long long int> cnt;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (auto u : cnt) {
    if (u.second / 2 > 0) {
      cnt[u.first + 1] += u.second / 2;
      if (u.second % 2)
        cnt[u.first] = 1;
      else
        cnt[u.first] = 0;
    }
  }
  long long int mx = -1;
  long long int count;
  for (auto u : cnt) {
    if (u.second) {
      count++;
      mx = max(mx, u.first);
    }
  }
  cout << mx + 1 - count;
  return 0;
}
