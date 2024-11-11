#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
const int N = 1e5 + 5;
int L[N], R[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &L[i], &R[i]);
  }
  sort(L, L + n);
  sort(R, R + n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += max(L[i], R[i]);
  }
  printf("%lld\n", sum + n);
  return 0;
}
