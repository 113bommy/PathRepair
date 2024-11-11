#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[1000001];
long long c[200005];
int main(void) {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
    b[a[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int k = sum - a[i];
    if (k % 2 != 0 || k > 2e6) {
      continue;
    }
    k /= 2;
    if (b[k] - (a[i] == k) > 0) {
      c[ans++] = i + 1;
    }
  }
  cout << ans << endl;
  if (ans) {
    for (int i = 0; i < ans; i++) {
      if (i != 0) printf(" ");
      printf("%lld", c[i]);
    }
  }
  return 0;
}
