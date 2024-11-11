#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
template <class T>
T sqr(T a) {
  return a * a;
}
int n, m;
double x;
int a[100000];
int b[100000];
int f1[100000];
int f2[100000];
int sum[100001];
void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[i] = -a[i];
  }
}
int ss[100010];
void solve() {
  int l = 0, r = 0;
  ss[0] = -1e9;
  for (int i = 0; i < n; ++i) {
    int tl = l, tr = r, mid, res = r + 1;
    while (tl <= tr) {
      mid = (tl + tr) >> 1;
      if (ss[mid] >= a[i]) {
        res = mid;
        tr = mid - 1;
      } else
        tl = mid + 1;
    }
    ss[res] = a[i];
    f1[i] = res;
    r = max(res, r);
  }
  memset(ss, 0, sizeof ss);
  ss[0] = -1e9;
  l = 0;
  r = 0;
  for (int i = n - 1; i >= 0; --i) {
    int tl = l, tr = r, mid, res = r + 1;
    while (tl <= tr) {
      mid = (tl + tr) >> 1;
      if (ss[mid] >= b[i]) {
        res = mid;
        tr = mid - 1;
      } else
        tl = mid + 1;
    }
    ss[res] = b[i];
    f2[i] = res;
    r = max(res, r);
  }
  for (int i = 0; i < n; ++i) {
    if (f1[i] + f2[i] - 1 == r) sum[f1[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    if (f1[i] + f2[i] - 1 != r) {
      printf("1");
      continue;
    }
    if (sum[f1[i]] == 1)
      printf("3");
    else
      printf("2");
  }
}
int main() {
  init();
  solve();
  return 0;
}
