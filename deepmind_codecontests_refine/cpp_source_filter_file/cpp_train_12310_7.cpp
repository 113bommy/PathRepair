#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> vec;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      int mp;
      cin >> mp;
      vec.push_back(mp);
    }
    sort(a, a + n);
    sort(vec.rbegin(), vec.rend());
    int sum = 0, x = k;
    for (int i = 0; i < k; i++) {
      if (a[0] > vec[i]) break;
      sum += vec[i];
      x--;
    }
    int total = 0;
    for (int i = k - x; i < n; i++) total += a[i];
    cout << total + sum << endl;
  }
  return 0;
}
