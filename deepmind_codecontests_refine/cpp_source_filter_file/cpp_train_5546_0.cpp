#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  int TESTCASE;
  cin >> TESTCASE;
  while (TESTCASE--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int z = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        z = 1;
      }
    }
    sort(a.begin(), a.end());
    vector<long long> res(5);
    res[0] = 1;
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;
    res[4] = 1;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < i; j++) {
        res[i] *= (a[j]);
      }
      for (int j = n - i - 1; j < n; j++) {
        res[i] *= (a[j]);
      }
    }
    if (z == 1) {
      res.push_back(0);
    }
    sort(res.begin(), res.end());
    cout << res[res.size() - 1] << endl;
  }
}
