#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  unordered_map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    m[t]++;
  }
  long long ans = ceil(n / 2.0);
  for (auto item : m) {
    ans -= ceil(item.second / 2.0);
  }
  cout << -ans;
}
