#include <bits/stdc++.h>
using namespace std;
long long a[3000000];
long long b[3000000];
long long c[3000000];
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld %lld", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (i == 1)
        c[i] = max(0ll, a[i] - b[n]);
      else {
        c[i] = max(0ll, a[i] - b[i - 1]);
      }
      sum += c[i];
    }
    long long minn = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      minn = min(minn, sum - c[i] + a[i]);
    }
    cout << minn << endl;
  }
}
