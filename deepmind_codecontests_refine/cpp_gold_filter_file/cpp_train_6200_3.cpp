#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int a[100000 + 100];
int n;
bool bs(int num, int low, int high) {
  int mid = (low + high) / 2;
  while (low <= high) {
    if (a[mid] < num)
      low = mid + 1;
    else if (a[mid] > num)
      high = mid - 1;
    else
      return true;
    mid = (low + high) / 2;
  }
  return false;
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> v(a + 1, a + n + 1);
    long long sum = 0;
    for (int i = 1; i < n; i++) {
      int cur = a[i];
      for (int j = 1, k = 1; k <= 32; j <<= 1, k++) {
        vector<int>::iterator low, high;
        low = lower_bound(v.begin() + i, v.end(), j - cur);
        high = upper_bound(v.begin() + i, v.end(), j - cur);
        if (low != high) {
          sum += (high - low);
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
