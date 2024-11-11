#include <bits/stdc++.h>
using namespace std;
int n;
int cu[1000005], cd[1000005];
long long tu[1000005], td[1000005];
char s[1000005];
int get_u(int i, int tar) {
  int l = 0, r = i;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (cu[i - 1] - cu[m - 1] >= tar)
      l = m;
    else
      r = m;
  }
  return l;
}
int get_d(int i, int tar) {
  int l = i, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (cd[m] - cd[i] >= tar)
      r = m;
    else
      l = m;
  }
  return r;
}
int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = (1); i <= (n); i++) {
    cu[i] = cu[i - 1];
    tu[i] = tu[i - 1];
    if (s[i] == 'U') {
      cu[i]++;
      tu[i] += n - i;
    }
    cd[i] = cd[i - 1];
    td[i] = td[i - 1];
    if (s[i] == 'D') {
      cd[i]++;
      td[i] += i;
    }
  }
  for (int i = (1); i <= (n); i++) {
    long long ans = 0;
    int left = cu[i - 1], right = cd[n] - cd[i];
    if (s[i] == 'U') {
      if (right > left) {
        int id = get_d(i, left + 1);
        ans += 2 * (td[id] - td[i] - 1LL * (left + 1) * i) + i;
        ans += 2 * (tu[i - 1] - 1LL * left * (n - i));
      } else {
        int id = get_u(i, right);
        ans += 2 * (td[n] - td[i] - 1LL * right * i);
        ans +=
            2 * (tu[i - 1] - tu[id - 1] - 1LL * right * (n - i)) + (n - i + 1);
      }
    } else {
      if (left > right) {
        int id = get_u(i, right + 1);
        ans += 2 * (td[n] - td[i] - 1LL * right * i);
        ans += 2 * (tu[i - 1] - tu[id - 1] - 1LL * (right + 1) * (n - i)) +
               (n - i + 1);
      } else {
        int id = get_d(i, left);
        ans += 2 * (td[id] - td[i] - 1LL * left * i) + i;
        ans += 2 * (tu[i - 1] - 1LL * left * (n - i));
      }
    }
    printf("%lld%c", ans, i == n ? '\n' : ' ');
  }
  return 0;
}
