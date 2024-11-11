#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx2,avx,fma")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int i, j, t;
  cin >> t;
  for (i = 0; i < t; i++) {
    int n;
    long long int s;
    cin >> n >> s;
    vector<pair<long long int, long long int> > v;
    long long int l, r;
    for (j = 0; j < n; j++) {
      cin >> l >> r;
      v.push_back(make_pair(l, r));
    }
    sort(v.rbegin(), v.rend());
    l = 1;
    r = s;
    while (l <= r) {
      long long int mid = (l + r) / 2;
      long long int sum = 0;
      int k = 0;
      for (j = 0; j < n; j++) {
        if (v[j].second >= mid && k < n / 2 + 1) {
          sum += max(v[j].first, mid);
          k++;
        } else
          sum += v[j].first;
      }
      if (k < (n / 2 + 1) || sum > s)
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << r << "\n";
  }
  return 0;
}
