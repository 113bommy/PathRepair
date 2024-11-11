#include <bits/stdc++.h>
const int maxn = 110000;
long long ans;
int l, n, t, x, y, n1, n2, low, hig;
int a1[maxn], a2[maxn];
inline int lb1(int x) {
  int l = 0, r = n1 + 1, v;
  while (l < r) {
    v = (l + r) >> 1;
    if (a1[v] < x)
      l = v + 1;
    else
      r = v;
  }
  return l;
}
inline int ub1(int x) {
  int l = 0, r = n1 + 1, v;
  while (l < r) {
    v = (l + r + 1) >> 1;
    if (a1[v] <= x)
      l = v;
    else
      r = v - 1;
  }
  return l;
}
inline int lb2(int x) {
  int l = 0, r = n2 + 1, v;
  while (l < r) {
    v = (l + r) >> 1;
    if (a2[v] < x)
      l = v + 1;
    else
      r = v;
  }
  return l;
}
inline int ub2(int x) {
  int l = 0, r = n2 + 1, v;
  while (l < r) {
    v = (l + r + 1) >> 1;
    if (a2[v] <= x)
      l = v;
    else
      r = v - 1;
  }
  return l;
}
int main() {
  scanf("%d%d", &l, &n);
  n1 = n2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &t, &x);
    if (t)
      a2[++n2] = x;
    else
      a1[++n1] = x;
  }
  std::sort(a1 + 1, a1 + n1 + 1);
  std::sort(a2 + 1, a2 + n2 + 1);
  a1[0] = a2[0] = -1;
  a1[n1 + 1] = a2[n2 + 1] = l + 1;
  if (!n1) {
    low = hig = 0;
    for (int i = 1; i <= n2; i++) {
      if (a2[i] == a2[1])
        ++low;
      else
        break;
    }
    for (int i = n2; i; i--) {
      if (a2[i] == a2[n2])
        ++hig;
      else
        break;
    }
    if (low == n2)
      printf("%I64d\n", n2 * ((long long)(n2 - 1)) * (n2 - 2) / 3);
    else
      printf("%I64d\n", low * ((long long)hig) * (n2 - 2) -
                            low * ((long long)hig) * (low - 1) / 2 -
                            hig * ((long long)low) * (hig - 1) / 2);
    return 0;
  }
  if (!n2) {
    low = hig = 0;
    for (int i = 1; i <= n1; i++) {
      if (a1[i] == a1[1])
        ++low;
      else
        break;
    }
    for (int i = n1; i; i--) {
      if (a1[i] == a1[n1])
        ++hig;
      else
        break;
    }
    if (low == n1)
      printf("%I64d\n", n1 * ((long long)(n1 - 1)) * (n1 - 2) / 3);
    else
      printf("%I64d\n", low * ((long long)hig) * (n1 - 2) -
                            low * ((long long)hig) * (low - 1) / 2 -
                            hig * ((long long)low) * (hig - 1) / 2);
    return 0;
  }
  if (a1[n1] < a2[1]) {
    low = hig = 0;
    for (int i = 1; i <= n2; i++) {
      if (a2[i] == a2[1])
        ++low;
      else
        break;
    }
    for (int i = n1; i; i--) {
      if (a1[i] == a1[n1])
        ++hig;
      else
        break;
    }
    printf("%I64d\n", low * ((long long)hig) * (low - 1) / 2 +
                          hig * ((long long)low) * (hig - 1) / 2 +
                          low * ((long long)hig) * (n1 + n2 - hig - low));
    return 0;
  }
  if (a2[n2] < a1[1]) {
    low = hig = 0;
    for (int i = 1; i <= n1; i++) {
      if (a1[i] == a1[1])
        ++low;
      else
        break;
    }
    for (int i = n2; i; i--) {
      if (a2[i] == a2[n2])
        ++hig;
      else
        break;
    }
    printf("%I64d\n", low * ((long long)hig) * (low - 1) / 2 +
                          hig * ((long long)low) * (hig - 1) / 2 +
                          low * ((long long)hig) * (n1 + n2 - hig - low));
    return 0;
  }
  ans = 0;
  if (a2[1] == 0 && a2[n2] == l) {
    low = hig = 0;
    for (int i = 1; i <= n2; i++) {
      if (a2[i] == a2[1])
        ++low;
      else
        break;
    }
    for (int i = n2; i; i--) {
      if (a2[i] == a2[n2])
        ++hig;
      else
        break;
    }
    ans += low * ((long long)hig) * (n2 - 2) -
           low * ((long long)hig) * (low - 1) / 2 -
           hig * ((long long)low) * (hig - 1) / 2;
  }
  if (a1[1] == 0 && a1[n1] == l) {
    low = hig = 0;
    for (int i = 1; i <= n1; i++) {
      if (a1[i] == a1[1])
        ++low;
      else
        break;
    }
    for (int i = n1; i; i--) {
      if (a1[i] == a1[n1])
        ++hig;
      else
        break;
    }
    ans += low * ((long long)hig) * (n1 - 2) -
           low * ((long long)hig) * (low - 1) / 2 -
           hig * ((long long)low) * (hig - 1) / 2;
  }
  for (int i = 1; i <= n1; i++) {
    x = lb2(a1[i]);
    y = ub2(a1[i]);
    t = y - x + 1;
    ans += t * ((long long)t - 1) / 2 + y * ((long long)n2 - y) +
           (x - 1) * ((long long)n2 - x + 1) - (n2 - y) * ((long long)x - 1);
  }
  for (int i = 1; i <= n2; i++) {
    x = lb1(a2[i]);
    y = ub1(a2[i]);
    t = y - x + 1;
    ans += t * ((long long)t - 1) / 2 + y * ((long long)n1 - y) +
           (x - 1) * ((long long)n1 - x + 1) - (n1 - y) * ((long long)x - 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
