#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
vector<int> v;
long long int pr[] = {2, 3, 5, 7, 11, 13, 17, 19};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int LT = 2LL * n * n;
  for (int i = 0; i < 8; i++) {
    v.clear();
    v.push_back(1);
    for (int j = 0; j <= i; j++) {
      long long int p = pr[j];
      long long int sz = v.size();
      for (int k = 0; k < sz; k++) {
        long long int z = v[k];
        while (z * p <= LT) {
          z *= p;
          v.push_back(z);
        }
      }
    }
    if (v.size() >= n) break;
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < n; i++) cout << v[i] << " ";
  cout << '\n';
}
