#include <bits/stdc++.h>
using namespace std;
int n;
long long ts, tf, t, i;
long long a[100100];
int main() {
  cin >> ts >> tf >> t;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long no = ts;
  long long sum = ts, smm = -1;
  for (i = 1; i <= n; i++) {
    if (no + t >= tf) break;
    if (no <= a[i] - 1) {
      cout << no;
      return 0;
    }
    if (a[i] > 0LL) {
      long long tmp = no - a[i] + 1;
      if (tmp < smm || smm == -1LL) {
        smm = tmp;
        sum = no - a[i] + 1;
      }
    }
    if (no <= a[i])
      no = a[i] + t;
    else
      no += t;
  }
  if (no + t <= tf && i == n + 1) {
    cout << no;
    return 0;
  }
  cout << sum;
  return 0;
}
