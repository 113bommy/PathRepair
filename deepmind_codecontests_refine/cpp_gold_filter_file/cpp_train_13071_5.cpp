#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const long long INF = 1e18;
long long power(long long x, long long y) {
  long long t = 1;
  while (y > 0) {
    if (y % 2)
      y -= 1, t = t * x % mod;
    else
      y /= 2, x = x * x % mod;
  }
  return t;
}
int arr[N];
set<int> S;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    arr[x]++;
    S.insert(x);
  }
  for (int i = N - 2; i >= 0; i--) arr[i] += arr[i + 1];
  long long mx = 0;
  for (typeof(S.begin()) it = S.begin(); it != S.end(); it++) {
    int l = *it;
    int cur = l;
    long long sum = 0;
    while (cur + l < N) {
      sum += 1ll * cur * (arr[cur] - arr[cur + l]);
      cur += l;
    }
    mx = max(sum, mx);
  }
  printf("%lld\n", mx);
  return 0;
}
