#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> a;
  long long num = 1, diff = 2;
  while (num <= n) {
    a.push_back(num);
    num = num + diff;
    diff++;
  }
  long long s = a.size();
  for (long long i = 0; i < s; i++) {
    if (binary_search(a.begin() + i, a.end(), n - a[i])) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
