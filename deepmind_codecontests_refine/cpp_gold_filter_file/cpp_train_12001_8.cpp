#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int min;
    int min_val = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (a[i] == min_val) {
        min = i;
        break;
      }
    }
    int m = 0;
    for (int j = 0; j < n; j++) {
      if (j != min) {
        while ((a[j] + min_val) <= k) {
          a[j] = a[j] + min_val;
          m++;
        }
      }
    }
    cout << m << endl;
  }
}
