#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int B[maxn];
void update(int u, int until, int val) {
  while (u <= until) {
    B[u] += val;
    u += u & (-u);
  }
}
int calc(int u) {
  int ans = 0;
  while (u) {
    ans += B[u];
    u -= u & (-u);
  }
  return ans;
}
int L[maxn], R[maxn];
long long inv[maxn];
int x[maxn], arr[maxn];
int main() {
  int n, num;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d", x + i);
    arr[i] = x[i];
  }
  num = n;
  sort(arr, arr + num);
  num = unique(arr, arr + num) - arr;
  for (int i = 0; i < n; i++) {
    x[i] = upper_bound(arr, arr + num, x[i]) - arr;
  }
  for (int i = 0; i < n; i++) {
    L[i] = i - calc(x[i]);
    update(x[i], num, 1);
  }
  memset(B, 0, sizeof(B));
  for (int i = n - 1; i >= 0; i--) {
    R[i] = calc(x[i] - 1);
    update(x[i], num, 1);
  }
  inv[0] = L[0] + R[0];
  for (int i = 1; i < n; i++) {
    inv[i] = inv[i - 1] + L[i] + R[i];
  }
  if (inv[n - 1] <= 2 * k) {
    cout << (long long)n * (n - 1) / 2 << endl;
    return 0;
  }
  memset(B, 0, sizeof(B));
  int cat = 1;
  update(x[1], num, 1);
  long long t = 0, ans = 0;
  for (int d = 1; d < n; d++) {
    while (cat < n - 1) {
      if (inv[n - 1] - 2 * (inv[cat] - inv[d - 1]) + 2 * t <= 2 * k) break;
      cat++;
      t += calc(cat - d - calc(x[cat]));
      update(x[cat], num, 1);
    }
    ans += n - cat - 1;
    t -= calc(x[d] - 1);
    update(x[d], num, -1);
  }
  cout << ans << endl;
  return 0;
}
