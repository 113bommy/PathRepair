#include <bits/stdc++.h>
using namespace std;
const long long mx = 4010;
long long posx[] = {1, -1, 0, 0};
long long posy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1, n, k, m, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v) {
      cin >> i;
    }
    long long x = *max_element(v.begin(), v.end());
    if (!k) {
      for (auto x : v) {
        cout << x << " ";
      }
      cout << endl;
    } else {
      if (k == 1) {
        for (long long i = 0; i < n; i++) {
          v[i] = x - v[i];
        }
      } else if (k > 1) {
        for (long long i = 0; i < n; i++) {
          v[i] = x - v[i];
        }
        k--;
        long long xx = *min_element(v.begin(), v.end());
        for (long long i = 0; i < n; i++) {
          if (k & 1) {
            v[i] = xx - v[i];
          }
        }
      }
      for (auto x : v) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
