#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
  long long n, k;
  cin >> n >> k;
  long long tedadm = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      tedadm++;
      if (i == n / i) {
        a.push_back(i);
        continue;
      }
      a.push_back(i);
      a.push_back(n / i);
    }
  }
  sort(a.begin(), a.end());
  if (k > a.size()) {
    cout << -1;
    return 0;
  }
  cout << a[k - 1];
  return 0;
}
