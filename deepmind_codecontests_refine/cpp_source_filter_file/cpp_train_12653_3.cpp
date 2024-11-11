#include <bits/stdc++.h>
using namespace std;
const int N = 201110;
int A[N], B[N], Max[N][20], Min[N][20];
int n;
int getbit(int x, int i) { return 1 & (x >> i); }
int getMin(int l, int r) {
  int k = r - l + 1, ans = (int)(1e9 + 7);
  for (int i = 0; i < 20; i++)
    if (getbit(k, i)) {
      ans = min(ans, Min[l][i]);
      l += 1 << i;
    }
  return ans;
}
int getMax(int l, int r) {
  int k = r - l + 1, ans = -(int)(1e9 + 7);
  for (int i = 0; i < 20; i++)
    if (getbit(k, i)) {
      ans = max(ans, Max[l][i]);
      l += 1 << i;
    }
  return ans;
}
int findlow(int k) {
  int ans = n + 1, inf = k, sup = n, mid;
  while (inf <= sup) {
    int mid = (inf + sup) / 2;
    if (getMax(k, mid) <= getMin(k, mid)) {
      if (getMax(k, mid) == getMin(k, mid)) ans = mid;
      sup = mid - 1;
    } else
      inf = mid + 1;
  }
  return ans;
}
int findhigh(int k) {
  int ans = 0, inf = k, sup = n, mid;
  while (inf <= sup) {
    int mid = (inf + sup) / 2;
    if (getMax(k, mid) >= getMin(k, mid)) {
      if (getMax(k, mid) == getMin(k, mid)) ans = mid;
      inf = mid + 1;
    } else
      sup = mid - 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    Max[i][0] = A[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &B[i]);
    Min[i][0] = B[i];
  }
  for (int k = 1; k < 20; k++) {
    for (int i = 1; i <= n; i++)
      if (i + (1 << k) <= n + 1) {
        Min[i][k] = min(Min[i][k - 1], Min[i + (1 << (k - 1))][k - 1]);
        Max[i][k] = max(Max[i][k - 1], Max[i + (1 << (k - 1))][k - 1]);
      }
  }
  long long ans = 0, l, r;
  for (int i = 1; i <= n; i++) {
    l = findlow(i);
    r = findhigh(i);
    if (l <= r) ans += r - l + 1;
  }
  cout << ans << endl;
}
