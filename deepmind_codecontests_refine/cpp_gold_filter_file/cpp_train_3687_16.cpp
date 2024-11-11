#include <bits/stdc++.h>
const long long mod = 1000000007;
const long double pi = 3.1415926536;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k, mn = 0, res;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < k; i++) {
    long long sum = v[i], t = i + k;
    v[i] = 10e5;
    while (t < n) {
      sum += v[t];
      v[t] = 10e5;
      t += k;
    }
    if (mn == 0 || sum < mn) {
      mn = sum;
      res = i + 1;
    }
  }
  cout << res;
  return 0;
}
