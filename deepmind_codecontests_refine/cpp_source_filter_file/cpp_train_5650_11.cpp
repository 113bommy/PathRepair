#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
      cout << "T\n";
      continue;
    }
    if (n == 2) {
      if (a[0] == a[1]) {
        cout << "TH\n";
      } else {
        cout << "T\n";
      }
      continue;
    }
    if (sum - a[n - 1] < a[n - 1]) {
      cout << "T\n";
      continue;
    }
    if (sum % 2 == 0) {
      cout << "TH\n";
      continue;
    }
    cout << "T\n";
  }
}
