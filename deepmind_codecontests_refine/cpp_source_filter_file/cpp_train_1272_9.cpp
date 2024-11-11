#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  map<long long, vector<long long>> vec;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    for (long long k = 0; k < 32; k++) {
      if (arr[i] & 1 << k) {
        vec[k].push_back(i);
      }
    }
  }
  long long ans = 0;
  for (auto itr = vec.rbegin(); itr != vec.rend(); itr++) {
    if (itr->second.size() == 1) {
      ans = *itr->second.begin();
      cout << arr[ans] << " ";
      break;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == ans) {
      continue;
    }
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
