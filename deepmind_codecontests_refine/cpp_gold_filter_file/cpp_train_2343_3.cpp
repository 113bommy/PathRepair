#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double EPS = 1e-9;
const int N = (int)4e6 + 500;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int first;
    scanf("%d", &first);
    a[first]++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] != 0) {
      a[i + 1] += a[i] / 2;
      ans += a[i] % 2;
    }
  }
  printf("%d", ans);
  return 0;
}
