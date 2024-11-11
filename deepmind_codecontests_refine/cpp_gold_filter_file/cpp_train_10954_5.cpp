#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
const long double pi = 3.1415926535898;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, a, sum = 0;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<long long int>> v(400005), w(400005);
  for (int i = 0; i < n; i++) {
    a = arr[i] - i;
    if (a > 0)
      v[a].push_back(arr[i]);
    else {
      a = abs(a);
      w[a].push_back(arr[i]);
    }
  }
  long long int maxi = 0;
  for (int i = 0; i < 400005; i++) {
    sum = 0;
    if (v[i].size() > 0) {
      for (int j = 0; j < v[i].size(); j++) sum += v[i][j];
      maxi = max(sum, maxi);
      sum = 0;
    }
    if (w[i].size() > 0) {
      for (int j = 0; j < w[i].size(); j++) sum += w[i][j];
      maxi = max(sum, maxi);
    }
  }
  cout << maxi << "\n";
  return 0;
}
