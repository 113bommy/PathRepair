#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  vector<long long> d;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      if ((n / i) != i) {
        d.push_back(n / i);
      }
    }
  }
  sort(d.begin(), d.end());
  if (k > d.size()) {
    cout << -1 << endl;
  } else {
    cout << d[k - 1] << endl;
  }
}
