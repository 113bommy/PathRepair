#include <bits/stdc++.h>
using namespace std;
int find(int x, int y, int n) {
  if (x > y) return find(y, x, n);
  return max(n - 1 - x, y);
}
int main(int argc, char const *argv[]) {
  int n, i;
  cin >> n;
  int a[n + 1];
  for (i = 0; i < n; i++) cin >> a[i];
  int min_i, max_i;
  for (i = 0; i < n; i++) {
    if (a[i] == 1) min_i = i;
    if (a[i] == n) max_i = i;
  }
  cout << find(min_i, max_i, n) << endl;
  return 0;
}
