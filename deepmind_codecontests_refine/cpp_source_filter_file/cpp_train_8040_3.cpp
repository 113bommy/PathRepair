#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
vector<vector<long long>> g;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long tt;
  cin >> tt;
  for (int t = 0; t < tt; ++t) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<long long> c(n);
    bool f = 0;
    for (int i = 0; i < n; ++i) {
      long long next = (i + (((a[i] / n) + 1ll) * n + a[i])) % n;
      c[next]++;
      if (c[next] > 1) {
        f = 1;
        break;
      }
    }
    string ret;
    if (f) {
      ret = "NO";
    } else {
      ret = "YES";
    }
    cout << ret << endl;
  }
  return 0;
}
