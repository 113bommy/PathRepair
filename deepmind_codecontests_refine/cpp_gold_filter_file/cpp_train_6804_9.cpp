#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  vector<long long> sum(n + 1);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; ++i) {
    if (!i)
      sum[i + 1] = v[i];
    else
      sum[i + 1] = sum[i] + v[i];
  }
  long long ero = 0;
  long long p = 0;
  long long pk = v[0];
  for (long long i = 0; i + p < v.size(); ++i) {
    for (; i + p + 1 < v.size();) {
      if (v[i + p + 1] * (p + 1) - (sum[i + p + 1] - sum[i]) <= k) {
        ++p;
        pk = v[i + p];
      } else
        break;
    }
  }
  cout << p + 1 << ' ' << pk << '\n';
}
