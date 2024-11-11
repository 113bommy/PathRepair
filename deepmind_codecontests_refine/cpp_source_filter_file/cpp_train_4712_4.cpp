#include <bits/stdc++.h>
using namespace std;
void checkpoint1() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  checkpoint1();
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    long long ans = 0;
    map<long long, long long> v;
    for (long long i = 0; i < n; i++) {
      long long y;
      cin >> y;
      if (y >= x)
        ans++;
      else {
        y = ceil((long double)x / y);
        v[y]++;
      }
    }
    long long op = 0;
    for (auto i : v) {
      i.second += op;
      ans += (i.second / i.first);
      op += (i.second % i.first);
    }
    cout << ans << "\n";
  }
  return 0;
}
