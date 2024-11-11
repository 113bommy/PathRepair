#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long sum = v[n - 1];
    long long now = v[n - 1];
    for (long long i = n - 2; i >= 0; i--) {
      if (now > v[i])
        sum += v[i], now = v[i];
      else if (now > 0)
        sum += now - 1;
    }
    cout << sum << endl;
  }
  return 0;
}
