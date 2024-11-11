#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    set<long long> s;
    for (long long x = 0; x < n; x++) {
      cin >> v[x];
    }
    long long index = -1;
    if (v[n - 1] >= v[n - 2]) {
      for (long long x = n - 1; x >= 1; x--) {
        if (v[x] < v[x - 1]) {
          index = x;
          break;
        }
      }
      cout << (index == -1 ? 0 : index) << "\n";
    } else {
      long long count = 0;
      long long index = -1;
      for (long long x = n - 1; x > 0; x--) {
        if (v[x] < v[x - 1] && count == 1) {
          index = x;
          break;
        }
        if (v[x] > v[x - 1]) {
          count = 1;
        }
      }
      cout << (index == -1 ? 0 : index) << "\n";
    }
  }
}
