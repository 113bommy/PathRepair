#include <bits/stdc++.h>
using namespace std;
long long int a[10000];
int main() {
  int n;
  long long int h;
  cin >> n >> h;
  int i, j;
  for (i = 0; i < n; i++) cin >> a[i];
  long long int sum = 0, sum1 = 0;
  int f = 0;
  int s = n - 1;
  int mid, ans;
  while (f < s) {
    mid = (f + s) / 2;
    sum = 0;
    priority_queue<long long int> p;
    for (i = 0; i <= mid; i++) {
      sum = sum + a[i];
      p.push(a[i]);
    }
    if (sum <= h) {
      f = mid + 1;
      ans = mid;
    } else {
      sum1 = 0;
      int k = 0;
      while (!p.empty()) {
        if (k % 2 == 0) sum1 = sum1 + p.top();
        p.pop();
        k++;
      }
      if (sum1 <= h) {
        f = mid + 1;
        ans = mid;
      } else
        s = mid - 1;
    }
  }
  cout << ans + 1;
  return 0;
}
