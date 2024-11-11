#include <bits/stdc++.h>
using namespace std;
long long t1, t2, t3;
int main() {
  long long TESTS = 1;
  while (TESTS--) {
    long long n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> cum(n + 1, 0);
    multiset<int> s;
    for (long long i = 0; i <= n - 1; i++) {
      long long cnt = 0;
      long long total = 0;
      cin >> v[i];
      cum[i] = v[i] + cum[i - 1];
      if (cum[i] > m) {
        for (auto j : s) {
          total += j;
          cnt++;
          if (total + cum[i] <= m) {
            break;
          }
        }
        cout << cnt << " ";
      } else {
        cout << 0 << " ";
      }
      s.insert(-v[i]);
    }
  }
}
