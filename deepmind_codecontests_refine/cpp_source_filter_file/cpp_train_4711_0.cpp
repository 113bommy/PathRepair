#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int tt = 0; tt < test; tt++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    int result = a[n - 1] - a[0];
    for (int i = 0; i < n; i++) {
      result = min(result, a[i + 1] - a[i]);
    }
    cout << result << endl;
  }
  return 0;
}
