#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n;
    long long a[n + 2];
    set<pair<long long, long long>> st;
    vector<long long> vec;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      st.insert({i, a[i]});
      vec.push_back(a[i]);
    }
    bool flag = true;
    for (long long i = 1; i <= min(100LL, n); i++) {
      flag = true;
      for (long long j = 2; j <= i + 1; j++) {
        if (a[i] % j != 0) flag = false;
      }
      if (flag) break;
    }
    if (flag)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
