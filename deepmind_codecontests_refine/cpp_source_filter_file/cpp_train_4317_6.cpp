#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q, a;
  cin >> n;
  std::vector<long long> x(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
    sum += x[i];
    x[i] = sum;
  }
  cin >> q;
  long long ans = 0;
  while (q--) {
    cin >> a;
    ans = (upper_bound(x.begin(), x.end(), a) - x.begin());
    cout << min(ans + 1, n) << endl;
  }
  return 0;
}
