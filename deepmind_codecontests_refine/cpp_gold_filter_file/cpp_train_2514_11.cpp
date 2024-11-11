#include <bits/stdc++.h>
using namespace std;
void show(int* a, long long n) {
  for (long long i = 0; i < n; i++) cout << a[i];
}
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  int a[n], ans[n];
  for (long long i = 0; i < n; i++) {
    a[i] = s[i] - 48;
    ans[i] = a[i];
  }
  int f[9];
  for (int i = 0; i < 9; i++) cin >> f[i];
  long long l, r, t;
  l = 0;
  t = a[l];
  while (l < n && t >= f[t - 1]) {
    l++;
    if (l >= n) break;
    t = a[l];
  }
  r = l + 1;
  t = a[r];
  while (r < n && t <= f[t - 1]) {
    r++;
    if (r >= n) break;
    t = a[r];
  }
  for (long long i = l; i < r && i < n; i++) {
    t = a[i] - 1;
    ans[i] = f[t];
  }
  show(ans, n);
  return 0;
}
