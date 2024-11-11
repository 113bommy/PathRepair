#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
int a[N];
int sz[N];
int cc[N];
int temp[N];
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++cc[a[i]];
  }
  int odd = 0;
  int l, r;
  for (i = 1; i <= n; ++i) {
    if (cc[i] & 1) ++odd;
  }
  if (odd > 1) {
    printf("0\n");
    return 0;
  }
  int mid;
  int ll, rr;
  l = 1, r = n;
  int t, x;
  int LEN = n / 2;
  while (l < r) {
    mid = (l + r) / 2;
    for (i = 1; i <= n; ++i) temp[i] = 0;
    for (i = 1; i <= mid; ++i) ++temp[a[i]];
    t = n - mid + 1;
    t = min(n - mid, mid);
    bool is = 1;
    for (i = 1; i <= t; ++i) {
      x = n - i + 1;
      if (temp[a[x]]) {
        --temp[a[x]];
      } else {
        is = 0;
        break;
      }
    }
    if (t < LEN) {
      for (i = 1; i <= n; ++i)
        if (temp[i]) is = 0;
      for (i = t + 1; i <= (n / 2); ++i) {
        x = n - i + 1;
        if (a[x] != a[i]) is = 0;
      }
    }
    if (is)
      r = mid;
    else
      l = mid + 1;
  }
  ll = l;
  l = 1, r = n;
  while (l < r) {
    mid = (l + r + 1) / 2;
    for (i = 1; i <= n; ++i) temp[i] = 0;
    for (i = n; i >= mid; --i) ++temp[a[i]];
    int len = min(n - mid + 1, mid - 1);
    int t = n - len + 1;
    bool is = 1;
    for (i = n; i >= t; --i) {
      x = n - i + 1;
      if (temp[a[x]] > 0) {
        --temp[a[x]];
      } else {
        is = 0;
        break;
      }
    }
    len = n - mid + 1;
    if (len < LEN) {
      for (i = 1; i <= n; ++i)
        if (temp[i]) is = 0;
      for (i = t - 1; i >= (n / 2); --i) {
        x = n - i + 1;
        if (a[x] != a[i]) is = 0;
      }
    }
    if (is)
      l = mid;
    else
      r = mid - 1;
  }
  rr = l;
  pair<int, int> v = make_pair(ll, rr);
  mid = (n + 1) / 2;
  int ind = 1, R = n;
  cerr << ll << " " << rr << endl;
  long long ret = 0;
  while (mid--) {
    if (v.first < ind) v.first = ind;
    if (R < v.first) v.first = R;
    if (v.second < ind) v.second = ind;
    if (R < v.second) v.second = R;
    ret += R - v.first + 1;
    ret += v.second - ind;
    if (a[R] != a[ind]) break;
    --R;
    ++ind;
  }
  cout << ret << endl;
}
