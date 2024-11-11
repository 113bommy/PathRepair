#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  valarray<int> v(n);
  vector<int> d;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 2; i <= n / 2; i++) {
    if (!(n % i) && n / i > 2) {
      d.push_back(i);
    }
  }
  int maxx = -1000;
  for (int i = 0; i < d.size(); i++) {
    for (int j = 0; j < d[i]; j++) {
      maxx = max(valarray<int>(v[slice(j, n / d[i], d[i])]).sum(), maxx);
    }
  }
  cout << maxx;
  return 0;
}
