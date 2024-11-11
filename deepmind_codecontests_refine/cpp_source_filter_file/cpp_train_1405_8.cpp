#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> v, cum_sum;
  long long sum = 0;
  long long mx = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v.push_back(a);
  }
  bool flag = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (j % 2 == 0)
        v[j] = (v[j] - 1) % n;
      else
        v[j] = (v[j] + 1) % n;
      if (v[j] < 0) v[j] = v[j] + n;
    }
    bool ck = true;
    for (long long j = 0; j < n - 1; j++) {
      if (v[j] > v[j + 1]) {
        ck = false;
        break;
      }
    }
    if (ck) {
      cout << "Yes"
           << "\n";
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "No"
         << "\n";
}
