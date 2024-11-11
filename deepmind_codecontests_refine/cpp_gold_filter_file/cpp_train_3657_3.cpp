#include <bits/stdc++.h>
using namespace std;
int a[524288];
long long s[524288];
long long pm[524288], sm[524288];
int num[524288];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = -a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = -a[i];
    s[i] = s[i - 1] + a[i];
  }
  long long ss = 0, ss2 = 0;
  int mn = 0, mn2 = 0;
  for (int i = n;; i--) {
    pm[i] = (long long)i * (i + 1) + ss2 - s[i];
    if (i == 0) {
      break;
    }
    sm[i] = s[i] - ss - (long long)i * (i - 1);
    if (sm[i] > i) {
      sm[i] = n + 1;
    }
    num[a[i]]++;
    if (a[i] < i) {
      ss += a[i];
    } else {
      ss += i;
      mn++;
    }
    ss -= mn;
    mn += num[i - 1];
    if (a[i] < i + 1) {
      ss2 += a[i];
    } else {
      ss2 += i + 1;
      mn2++;
    }
    ss2 -= mn2;
    mn2 += num[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sm[i] < sm[i - 1]) {
      sm[i] = sm[i - 1];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (pm[i] > pm[i + 1]) {
      pm[i] = pm[i + 1];
    }
  }
  a[0] = n + 1;
  int now = n;
  bool ok = false;
  for (int i = 0; i <= n; i++) {
    while (a[now] < i) {
      now--;
    }
    if ((i + s[n]) & 1) {
      continue;
    }
    if (i > pm[now]) {
      continue;
    }
    if (i < sm[now]) {
      continue;
    }
    if (ok) {
      putchar(' ');
    }
    ok = true;
    printf("%d", i);
  }
  if (!ok) {
    printf("-1");
  }
  putchar('\n');
  return 0;
}
