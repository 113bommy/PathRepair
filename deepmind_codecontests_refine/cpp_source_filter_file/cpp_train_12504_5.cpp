#include <bits/stdc++.h>
using namespace std;
long long int A[200005];
int main() {
  int n;
  long long int k;
  scanf("%d%lld", &n, &k);
  int targ = (-1) ^ (1 << 31);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A[a]++;
    targ = min(targ, a);
  }
  for (int i = 200003; i >= 0; i--) {
    A[i] += A[i + 1];
  }
  long long int tmp = 0;
  int ans = 0;
  for (int i = 20; i > targ; i--) {
    if (tmp + A[i] <= k) {
      tmp += A[i];
    } else {
      tmp = A[i];
      ans++;
    }
  }
  if (tmp > 0) {
    ans++;
  }
  printf("%d\n", ans);
}
