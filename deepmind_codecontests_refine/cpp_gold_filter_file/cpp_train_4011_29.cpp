#include <bits/stdc++.h>
using namespace std;
long long ans = 1;
int n, s[64], x[64];
int carry(int i) {
  if (i == 0) {
    if (s[i] == 1 and x[i] == 0) {
      return 1;
    } else if (s[i] == 1 and x[i] == 1) {
      ans *= 2;
      return 0;
    }
  }
  if (i == n - 1 and s[i] != x[i]) {
    ans = 0;
    return 0;
  }
  if (carry(i - 1) == 1) {
    if (s[i] == 0 and x[i] == 0) {
      return 0;
    } else if (s[i] == 1 and x[i] == 0) {
      return 1;
    } else if (s[i] == 0 and x[i] == 1) {
      ans *= 2;
      return 1;
    } else if (s[i] == 1 and x[i] == 1) {
      ans = 0;
      return 0;
    }
  } else {
    if (s[i] == 0 and x[i] == 0) {
      return 0;
    } else if (s[i] == 1 and x[i] == 0) {
      return 1;
    } else if (s[i] == 0 and x[i] == 1) {
      ans = 0;
      return 0;
    } else if (s[i] == 1 and x[i] == 1) {
      ans *= 2;
      return 0;
    }
  }
}
int main() {
  long long sum, xr, s1, x1;
  cin >> sum >> xr;
  s1 = sum;
  x1 = xr;
  if (xr > sum) {
    cout << 0 << '\n';
    return 0;
  }
  while (sum > 0) {
    s[n] = sum % 2;
    x[n] = xr % 2;
    sum /= 2;
    xr /= 2;
    ++n;
  }
  for (int j = 0; j < n / 2; ++j) {
    swap(s[j], s[n - 1 - j]);
    swap(x[j], x[n - 1 - j]);
  }
  carry(n - 1);
  if (s1 == x1) ans -= 2;
  cout << ans << '\n';
  return 0;
}
