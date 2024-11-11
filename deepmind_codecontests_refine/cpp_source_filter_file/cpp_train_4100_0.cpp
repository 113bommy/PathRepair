#include <bits/stdc++.h>
using namespace std;
bool func(pair<double, double> a, pair<double, double> b) {
  return (a.first < b.first);
}
int n;
pair<double, double> a[100001];
int main() {
  cin >> n;
  int k, a;
  int ans = 0;
  int maxk = 0;
  for (int i = 0; i < n; i++) {
    cin >> k >> a;
    maxk = max(maxk, k);
    int second = 1;
    int m = 0;
    while (second > a) {
      second *= 4;
      m++;
    }
    ans = max(ans, k + m);
  }
  if (ans == maxk) ans++;
  cout << ans;
}
