#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  bool flag = true;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    v.push_back(y);
    if (x == y) flag = false;
  }
  long long cnt = 0;
  if (flag) {
    v.push_back(x);
    n++;
    cnt++;
  }
  sort(v.begin(), v.end());
  long long low = lower_bound(v.begin(), v.end(), x) - v.begin();
  long long high = upper_bound(v.begin(), v.end(), x) - v.begin();
  high--;
  long long mid = ((n + 1) / 2) - 1;
  if (v[mid] == x)
    cout << cnt << endl;
  else {
    if (low > mid) {
      while (1) {
        n++;
        cnt++;
        if (((n + 1) / 2) - 1 == low) break;
      }
      cout << cnt << endl;
    } else if (high < mid) {
      while (1) {
        high++;
        n++;
        cnt++;
        if (((n + 1) / 2) - 1 == high) break;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
