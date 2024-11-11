#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[101] = {0};
  for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    a[t] += 1;
  }
  long long ans = 0;
  while (1) {
    long long tp = 0;
    for (long long i = 0; i < 101; i++) {
      long long r;
      if (a[i] >= i + 1 - tp) {
        r = (i + 1) - tp;
        tp += r;
        a[i] -= r;
      } else if (a[i] > 0) {
        r = a[i];
        tp += r;
        a[i] -= r;
      } else {
        continue;
      }
    }
    if (tp > 0)
      ans++;
    else
      break;
  }
  cout << ans << endl;
}
