#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long j = 0; j < t; j++) {
    long long l, r;
    cin >> l >> r;
    long long x = l;
    while (x < r) {
      vector<int> v;
      long long n = x;
      while (n > 0) {
        int digit = n % 10;
        v.push_back(digit);
        n /= 10;
      }
      set<long long> second(v.begin(), v.end());
      if (second.size() == v.size()) {
        cout << x;
        return 0;
      }
      x++;
    }
    cout << -1;
  }
  return 0;
}
