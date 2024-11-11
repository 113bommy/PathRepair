#include <bits/stdc++.h>
using namespace std;
int n, a[1001000];
void init() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
}
void work() {
  for (int i = (2); i <= (n); ++i)
    if (a[i - 1] > a[i]) a[1] -= a[i - 1] - a[1];
  puts(a[1] >= 0 ? "YES" : "NO");
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    init();
    work();
  }
  return 0;
}
