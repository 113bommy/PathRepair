#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long sum = 0;
  int tt = 0;
  for (int i = 0; i < n; i++) {
    if (sum - (long long)(n - i - 1) * a[i] * tt < k) {
      printf("%d\n", i + 1);
    } else {
      sum += (long long)a[i] * tt;
      tt++;
    }
  }
  return 0;
}
