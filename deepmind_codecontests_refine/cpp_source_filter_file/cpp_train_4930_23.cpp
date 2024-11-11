#include <bits/stdc++.h>
using namespace std;
const int maxn = 1020;
const int maxx = 10000;
const int MOd = 1e9 + 7;
const int K = 750;
int a, L[maxn], R[maxn];
pair<int, int> ar[maxn];
long long s[maxn], T[maxn];
double ans[maxn];
int findl(int n) {
  if (n == L[n]) return n;
  return L[n] = findl(L[n]);
}
int findr(int n) {
  if (n == R[n]) return n;
  return R[n] = findr(R[n]);
}
int main() {
  scanf("%d", &a);
  for (int i = 1; i <= a; i++) scanf("%d", &ar[i].first), ar[i].second = i;
  sort(ar + 1, ar + 1 + a);
  for (int i = 1; i <= a; i++) L[i] = i, R[i] = i;
  R[a + 1] = a + 1;
  for (int i = a; i >= 1; i--) {
    L[ar[i].second] = ar[i].second - 1;
    R[ar[i].second] = ar[i].second + 1;
    int l = ar[i].second - findl(ar[i].second);
    int r = findr(ar[i].second) - ar[i].second;
    if (l > r) swap(l, r);
    T[1] += ar[i].first;
    T[l + 1] -= ar[i].first;
    T[r + 1] -= ar[i].first;
    T[r + l + 1] += ar[i].first;
  }
  for (int i = 1; i <= a; i++) s[i] = s[i - 1] + T[i];
  long long k = 0;
  for (int i = 1; i <= a; i++) {
    k += s[i];
    ans[i] = (double)k / (a - i + 1);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    printf("%lf\n", ans[t]);
  }
  return 0;
}
