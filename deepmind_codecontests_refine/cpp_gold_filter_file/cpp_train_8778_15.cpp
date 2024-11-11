#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, a, b, sum = 0;
  cin >> n >> m;
  map<long long int, long long int> m1;
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b;
    m1[b] += a;
  }
  long long int k = 0;
  for (auto i = m1.rbegin(); i != m1.rend(); i++) {
    if ((k + (i->second)) <= n) {
      sum += (i->second) * (i->first);
      k += (i->second);
    } else {
      sum += (n - k) * (i->first);
      break;
    }
  }
  cout << sum;
  return 0;
}
