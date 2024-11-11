#include <bits/stdc++.h>
using namespace std;
const int N = 100252;
int a[N];
int b[N];
int c[N];
int ans[N];
int main() {
  int n;
  memset(b, 0, sizeof(b)), memset(c, 0, sizeof(c));
  scanf("%d", &n);
  int ma = 0;
  int tma = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = n - 1;
  while (a[l] < a[l + 1] && l < n) l++;
  while (a[r] < a[r - 1] && r >= 0) r--;
  b[l] = a[l];
  c[r] = c[r];
  for (int i = l; i <= r; i++) {
    b[i] = max(b[i - 1] + 1, a[i]);
  }
  for (int i = r; i >= l; i--) {
    c[i] = max(c[i + 1] + 1, a[i]);
  }
  for (int i = l; i <= r; i++) {
    ans[i] = min(b[i], c[i]);
  }
  for (int i = l; i <= r; i++) {
    if (ans[i] == ans[i + 1]) ans[i + 1]++;
  }
  int sum = 0;
  for (int i = l; i <= r; i++) {
    sum += ans[i] - a[i];
  }
  cout << sum << endl;
  return 0;
}
