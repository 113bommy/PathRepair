#include <bits/stdc++.h>
using namespace std;
int n;
long long x, y, step;
bool dd[2000005];
long long a[2000005], s[2000005];
long long res = 1ll * 1000000000000000007;
void nhap() {
  cin >> n >> x >> y;
  step = x / y;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i < 2000005; i++) {
    s[i] = s[i - 1] + a[i] * i;
    a[i] += a[i - 1];
  }
}
void prepare() {
  dd[0] = dd[1] = 1;
  for (int i = 2; i < 2000005; i++)
    if (!dd[i]) {
      long long cur = 0;
      for (int j = i * 2; j < 2000005; j += i) dd[j] = 1;
      if (step >= (i - 1)) {
        for (int j = i; j < 2000005; j += i)
          cur += 1ll * ((a[j - 1] - a[j - i]) * j - (s[j - 1] - s[j - i])) *
                 1ll * y;
      } else {
        for (int j = i; j < 2000005; j += i) {
          cur += 1ll *
                 ((a[j - 1] - a[j - step - 1]) * j -
                  (s[j - 1] - s[j - step - 1])) *
                 1ll * y;
          cur += 1ll * x * (a[j - step - 1] - a[j - i]);
        }
      }
      if (cur < res) res = cur;
    }
  cout << res;
}
int main() {
  nhap();
  prepare();
}
