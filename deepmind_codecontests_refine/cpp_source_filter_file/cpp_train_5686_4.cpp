#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<long long>> a;
  bool tr = true;
  for (long long l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    a.push_back({l, r});
  }
  sort(a.begin(), a.end(),
       [](const vector<long long>& a, const vector<long long>& b) -> bool {
         if (a[0] == b[0]) {
           return a[1] < b[1];
         } else {
           return a[0] < b[0];
         }
       });
  long long f = 0, s = 0;
  for (long long i = 0; i < n; i++) {
    if (tr && a[i][0] > f) {
      f = a[i][1];
    } else if (tr && a[i][0] > s) {
      s = a[i][1];
    } else {
      tr = false;
    }
  }
  if (tr) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
