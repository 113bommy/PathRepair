#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int sm = 0;
  vector<long long int> v;
  for (long long int i = 1; i <= 10000; i++) {
    sm += i;
    v.push_back(sm);
  }
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int d = abs(a - b);
    if (d == 0) {
      cout << 0 << endl;
      continue;
    }
    int p = (lower_bound(v.begin(), v.end(), d) - v.begin());
    while (v[p] % 2 != d % 2) p++;
    cout << p + 1 << endl;
  }
}
