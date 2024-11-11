#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 1e5 + 10;
int n, s1, s2;
int a[maxn];
int check(int p) {
  int l = a[n] - p, r = a[n] + p;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] < l || a[i] > r) {
      l = max(l, a[i] - p);
      r = min(r, a[i] + p);
      if (l > r) return 0;
    } else {
      l = a[i] - p;
      r = a[i] + p;
    }
  }
  if (s1 >= l && s1 <= r || s2 >= l && s2 <= r) return 1;
  return 0;
}
int main() {
  cin >> n >> s1 >> s2;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int L = abs(s1 - s2), R = 1e9 + 10;
  while (1) {
    if (L + 1 >= R) {
      if (check(L))
        cout << L;
      else
        cout << R;
      break;
    }
    if (check((L + R) / 2))
      R = (L + R) / 2;
    else
      L = (L + R) / 2 + 1;
  }
  return 0;
}
