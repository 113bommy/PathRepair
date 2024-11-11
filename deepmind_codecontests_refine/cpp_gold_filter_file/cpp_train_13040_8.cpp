#include <bits/stdc++.h>
using namespace std;
const long MIN = 1e9;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long a[n], b[n];
    long am = MIN, bm = MIN;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (am > a[i]) am = a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (bm > b[i]) bm = b[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum = (long long)sum + max((a[i] - am), (b[i] - bm));
    }
    cout << sum << endl;
  }
  return 0;
}
