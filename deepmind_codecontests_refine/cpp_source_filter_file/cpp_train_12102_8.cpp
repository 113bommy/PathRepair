#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    vector<long long> v, b;
    cin >> n >> k;
    long long a[n], f = 0;
    set<long long> s;
    set<long long>::iterator itr;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    long long t = s.size();
    if (t > k) {
      f = 0;
    } else {
      f = 1;
      for (itr = s.begin(); itr != s.end(); itr++) {
        v.push_back(*itr);
      }
      for (long long i = 0; i < k; i++) {
        b.push_back(v[i % t]);
      }
    }
    if (f == 0) {
      cout << -1;
    } else {
      cout << n * n << "\n";
      for (long long i = 0; i < n * n; i++) {
        cout << b[i % k];
      }
    }
    cout << "\n";
  }
}
