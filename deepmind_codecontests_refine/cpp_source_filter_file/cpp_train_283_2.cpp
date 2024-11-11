#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 123;
const int M = 1000 * 1000 + 123;
int n;
int k;
int a[N];
int x[M];
int ps[M];
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    x[a[i]] = 1;
  }
  sort(a, a + n);
  for (int i = 1; i < M; i++) {
    ps[i] = ps[i - 1] + x[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l = a[i] + 1;
    int r = max(M - 1, a[i] + k);
    int sum = ps[r] - ps[l - 1];
    if (sum == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
