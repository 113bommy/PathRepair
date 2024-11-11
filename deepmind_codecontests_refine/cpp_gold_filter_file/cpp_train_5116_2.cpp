#include <bits/stdc++.h>
using namespace std;
int a[1005];
int n, h;
bool check(int k) {
  vector<int> v;
  for (int i = 1; i <= k; i++) v.push_back(a[i]);
  sort(v.begin(), v.end());
  long long sum = 0;
  for (int i = k - 1; i >= 0; i -= 2) {
    sum += v[i];
  }
  if (sum <= h)
    return true;
  else
    return false;
}
int main() {
  while (cin >> n >> h) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 1;
    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << r << endl;
  }
}
