#include <bits/stdc++.h>
using namespace std;
long long n = 1, a[1000000], l, r;
void rec(long long cur) {
  if (cur > 4444444777) return;
  if (cur != 0) {
    a[n] = cur;
    n++;
  }
  cur *= 10;
  rec(cur + 7);
  rec(cur + 4);
}
int main() {
  long long i, j, k, s = 0, res = 0;
  cin >> l >> r;
  rec(0);
  sort(a, a + n);
  i = 0;
  while (a[i] < l) i++;
  long long left = i;
  i = n - 1;
  while (a[i] > r) i--;
  long long right = i;
  if (left > right) {
    cout << (r - l + 1) * a[left];
    return 0;
  }
  res += a[left] * (a[left] - l + 1);
  res += a[right + 1] * (r - a[right]);
  for (i = left + 1; i <= right; i++) res += a[i] * (a[i] - a[i - 1]);
  cout << res;
  return 0;
}
