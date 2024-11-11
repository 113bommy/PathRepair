#include <bits/stdc++.h>
using namespace std;
const int M = 400 * 1000 + 4, Inf = 1e9 + 10;
pair<int, int> a[M];
int b[M];
int main() {
  ios::sync_with_stdio(false);
  int n, j = 0;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a[i] = make_pair(x, i);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i].first <= j)
      b[a[i].second] = ++j;
    else
      j = b[a[i].second] = a[i].first;
  }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  return 0;
}
