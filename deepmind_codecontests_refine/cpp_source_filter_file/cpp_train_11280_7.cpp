#include <bits/stdc++.h>
using namespace std;
void fast();
long long int ar[200005];
long long int n, a, b, c, d, m, k, q, mod;
vector<long long int> v;
int32_t main() {
  fast();
  long long int t = 1;
  while (t--) {
    cin >> n >> m >> k;
    if (k == 1) {
      long long int day = 1;
      while (day < n + m) {
        v.push_back(day);
        day += n - 1;
      }
      cout << v.size() << "\n";
      for (auto x : v) cout << x << " ";
      cout << "\n";
      return 0;
    }
    long long int day = 1;
    long long int bag = 0;
    long long int type = 1;
    for (long long int i = 0; i < k; i++) v.push_back(1);
    day = n;
    while (day < (n + m)) {
      if (type == 1) {
        v.push_back(day);
        day++;
        type = 0;
      } else {
        for (long long int i = 0; i < k - 1; i++) v.push_back(day);
        day += n - 1;
        type = 1;
      }
    }
    cout << v.size() << "\n";
    for (auto x : v) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
