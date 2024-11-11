#include <bits/stdc++.h>
using namespace std;
bool sv[1010] = {0};
struct ab {
  int a, i;
};
bool cmp(ab a, ab b) { return a.a < b.a; }
int main() {
  int i, n, k, j, x, a[10110], b[1010], c[1010], cost = 0, co, m;
  ab arr[1010];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    arr[i].a = x;
    arr[i].i = i;
  }
  sort(arr, arr + n, cmp);
  cin >> m;
  for (i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
  for (i = 0; i < n - 1; i++) {
    co = 100000000;
    for (j = 0; j < m; j++) {
      if (b[j] == (arr[i].i + 1) && co > c[j]) {
        co = c[j];
      }
    }
    if (co != 100000000)
      cost += co;
    else
      break;
  }
  if (i == n - 1)
    cout << cost << endl;
  else
    cout << -1 << endl;
  return 0;
}
