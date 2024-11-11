#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<short> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> p;
  for (int i = 2; i <= (int)sqrt(sum) + 1; i++) {
    if (sum % i == 0) {
      p.push_back(i);
      while (sum % i == 0) sum /= i;
    }
  }
  if (sum > 1) p.push_back(sum);
  if (p.size() == 0) {
    cout << -1;
    return 0;
  }
  long long minans = 9e17;
  for (int q = 0; q < p.size(); q++) {
    int m = p[q] / 2 + p[q] % 2;
    int l = 0;
    long long ans = 0;
    int cnt = 0;
    while (l < n) {
      for (int i = l; i < n; i++, l++) {
        ans += cnt;
        cnt += a[i];
        if (cnt == m) {
          cnt -= p[q] % 2;
          break;
        }
      }
      for (int i = l + 1; i < n; i++, l++) {
        ans += cnt;
        cnt -= a[i];
        if (cnt == 0) {
          l = i + 1;
          break;
        }
      }
    }
    minans = min(ans, minans);
  }
  cout << minans;
}
