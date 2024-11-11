#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  {
    long long int i;
    long long int x[3], y[3];
    vector<pair<long long int, long long int>> v;
    for (i = 0; i < 3; i++) {
      cin >> x[i] >> y[i];
      v.push_back({x[i], y[i]});
    }
    sort((v).begin(), (v).end());
    sort(x, x + 3);
    sort(y, y + 3);
    cout << x[2] - x[0] + y[2] - y[0] + 1 << '\n';
    for (i = x[0]; i < x[1]; i++) {
      cout << i << ' ' << v[0].second << '\n';
    }
    for (i = x[1]; i <= x[2]; i++) {
      cout << i << ' ' << v[2].second << '\n';
    }
    for (i = y[0]; i < y[2]; i++) {
      cout << v[1].first << ' ' << i << "\n";
    }
    cout << '\n';
  }
  return 0;
}
