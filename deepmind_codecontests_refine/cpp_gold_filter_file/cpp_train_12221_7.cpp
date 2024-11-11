#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 3;
int prime[MAXN], A[MAXN];
long long cm[MAXN], cm1[MAXN];
vector<int> P;
void pre() {
  for (int i = 2; i < MAXN; i++) {
    if (!prime[i]) {
      for (int l = i; l < MAXN; l += i) prime[l] = i;
      P.push_back(i);
    }
  }
}
long long cnt(int idx, long long n) {
  long long res = 0;
  for (long long i = P[idx]; i <= n; i *= P[idx]) res += n / i;
  return res;
}
void fact(int n, int x) {
  while (n > 1) {
    cm1[prime[n]] += x;
    n /= prime[n];
  }
}
int main() {
  int n;
  pre();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]), cm[A[i]]++;
  for (int i = MAXN - 3; i; i--) cm[i] += cm[i + 1];
  sort(A, A + n);
  for (int i = 1; i <= A[n - 1]; i++) fact(i, cm[i]);
  long long res = 1;
  for (int i = 0; i < P.size(); i++) {
    if (!cm1[P[i]]) continue;
    long long l = 0, r = (1LL << 50);
    while (l <= r) {
      long long md = (l + r) >> 1;
      if (cnt(i, md) >= cm1[P[i]])
        r = md - 1;
      else
        l = md + 1;
    }
    res = max(res, r + 1);
  }
  printf("%I64d\n", res);
}
