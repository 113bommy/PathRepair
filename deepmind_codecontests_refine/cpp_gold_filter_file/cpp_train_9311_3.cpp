#include <bits/stdc++.h>
using namespace std;
long long n, a[1000001], l[1000001], r[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    l[i] = 1;
    r[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) l[i] += l[i - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) r[i] += r[i + 1];
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    long long tmp = 0;
    if (i - 1 >= 0) tmp += l[i - 1];
    if (i + 1 < n) tmp += r[i + 1];
    if (i - 1 >= 0 and i + 1 < n) {
      if (a[i - 1] > a[i + 1] || a[i + 1] - a[i - 1] <= 1)
        tmp = max(l[i - 1], r[i + 1]);
    }
    tmp++;
    cnt = max(cnt, tmp);
  }
  cout << cnt;
  return 0;
}
