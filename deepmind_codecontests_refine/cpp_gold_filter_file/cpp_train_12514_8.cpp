#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> even;
    vector<long long> e;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if ((a[i] % 2) == 0) {
        if (even[a[i]] == 0) e.push_back(a[i]);
        even[a[i]]++;
      }
    }
    map<long long, long long> rev;
    for (long long i = 0; i < e.size(); i++) {
      long long temp = e[i], two = 0;
      while (temp % 2 == 0) {
        two++;
        temp /= 2;
      }
      rev[temp] = max(two, rev[temp]);
    }
    long long count = 0;
    for (auto d : rev) {
      count += d.second;
    }
    cout << count << endl;
  }
  return 0;
}
