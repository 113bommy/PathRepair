#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 20;
long long n, a[MAXN], l[MAXN], r[MAXN], g, ansl, ansr;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    l[i] = g;
    if (a[i] == 1) g++;
  }
  g = 0;
  for (int i = n; i >= 1; i--) {
    r[i] = g;
    if (a[i] == 0) g++;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) ansl += l[i];
  for (int i = n; i >= 1; i--)
    if (a[i] == 1) ansr += r[i];
  cout << min(ansl, ansr);
  return 0;
}
