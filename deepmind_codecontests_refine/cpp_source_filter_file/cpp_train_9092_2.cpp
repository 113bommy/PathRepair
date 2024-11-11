#include <bits/stdc++.h>
using namespace std;
int n, x, a[10], s, r;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    s += x;
    a[x]++;
  }
  if (!a[0]) return cout << -1, 0;
  int j = s % 3;
  while (s % 3 && j < 10) {
    if (a[j]) a[j]--, s -= j;
    j += 3;
  }
  j = 1 + (s % 3 == 1);
  int cnt = 0;
  while (s % 3 && j < 10) {
    if (a[j] && cnt < 2) s -= j, a[j]--, cnt++;
    j += 3;
  }
  if (s == 0) return cout << 0, 0;
  if (s % 3) return cout << -1, 0;
  for (int i = 9; i >= 0; --i)
    while (a[i]--) cout << i;
}
