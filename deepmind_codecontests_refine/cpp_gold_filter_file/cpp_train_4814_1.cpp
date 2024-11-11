#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    long rich;
    long double sum = 0;
    cin >> n >> rich;
    vector<long double> v(n);
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (i = n - 1; i >= 0; i--) {
      sum += v[i];
      if (sum / (n - i) < rich) break;
    }
    cout << n - i - 1 << endl;
  }
  return 0;
}
