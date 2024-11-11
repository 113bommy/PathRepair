#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  long long sum1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum1 += a[i];
  }
  int o[n];
  o[0] = 0;
  int x = 0;
  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    cnt++;
    o[i] = i - a[i];
    if (x + cnt < o[i]) {
      o[i] = x + cnt;
    }
    int xx = i + 1 - a[i + 1];
    if (xx > x + cnt + 1) {
      xx = x + cnt + 1;
    }
    if (o[i - 1] >= o[i] && o[i] < xx) {
      x = o[i];
      cnt = 0;
    }
  }
  o[n - 1] = n - 1 - a[n - 1];
  if (x + cnt + 1 < o[n - 1]) {
    o[n - 1] = x + cnt + 1;
  }
  long long sum = o[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (o[i] > o[i + 1]) {
      o[i] = o[i + 1];
      sum += o[i + 1];
    } else {
      sum += o[i];
    }
  }
  long long val = (n * (n - 1)) / 2 - sum - sum1;
  cout << val << endl;
  return 0;
}
