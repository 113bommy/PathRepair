#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long s = 0;
    long long m = 0;
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
      m = m ^ a[j];
      s += a[j];
    }
    cout << 2 << "\n";
    cout << s << " " << s + m << "\n";
  }
}
