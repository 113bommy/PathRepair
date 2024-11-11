#include <bits/stdc++.h>
using namespace std;
char s[101][101];
long long n, k;
long long func(long long i, long long j) {
  long long l = 0, r = 0, u = 0, d = 0;
  for (long long t = i - 1; t >= 1; t--) {
    if (s[t][j] == '.') {
      u++;
    } else {
      break;
    }
  }
  for (long long t = i + 1; t <= n; t++) {
    if (s[t][j] == '.') {
      d++;
    } else {
      break;
    }
  }
  for (long long t = j + 1; t <= n; t++) {
    if (s[i][t] == '.') {
      r++;
    } else {
      break;
    }
  }
  for (long long t = j - 1; t >= 1; t--) {
    if (s[i][t] == '.') {
      l++;
    } else {
      break;
    }
  }
  long long ans = 0;
  if (l > k) {
    l = k - 1;
  }
  if (u > k) {
    u = k - 1;
  }
  for (long long t = j - l; t <= j; t++) {
    if (t + (k - 1) <= j + r) {
      ans++;
    } else {
      break;
    }
  }
  for (long long t = i - u; t <= i; t++) {
    if (t + (k - 1) <= i + d) {
      ans++;
    } else {
      break;
    }
  }
  return ans;
}
int main() {
  scanf("%lld", &n), scanf("%lld", &k);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }
  long long mx = -1, x = 1, y = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        long long tmp = func(i, j);
        if (tmp > mx) {
          mx = tmp;
          x = i;
          y = j;
        }
      }
    }
  }
  printf("%lld %lld\n", x, y);
  return 0;
}
