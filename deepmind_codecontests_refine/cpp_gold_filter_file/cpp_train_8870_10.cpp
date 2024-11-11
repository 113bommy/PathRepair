#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  long long arr[n];
  long long ct = 0;
  vector<double> v;
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] % (a + b) <= a && arr[i] % (a + b) != 0)
      ct++;
    else {
      if (arr[i] % (a + b) == 0) {
        v.push_back(ceil((double)b / a));
      } else {
        long long m = arr[i] % (a + b) - a;
        v.push_back(ceil((double)m / a));
      }
    }
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); ++i) {
    if (v[i] <= k) {
      ct++;
      k -= (long long)v[i];
    } else {
      break;
    }
  }
  cout << ct << endl;
  return 0;
}
