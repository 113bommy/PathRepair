#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100001];
int main() {
  int n, i, j, k, t, sum;
  while (cin >> n >> k) {
    sum = 0;
    j = 0;
    for (i = 0; i < n; i++) {
      cin >> t;
      if (a[j] != t) a[++j] = t;
    }
    for (i = 1; i <= j; i++) {
      if (a[i - 1] == a[i + 1])
        b[a[i]] += 2;
      else
        b[a[i]] += 1;
    }
    int ans = 0;
    for (i = 1; i <= k; i++) {
      if (b[i] > b[ans]) ans = i;
    }
    cout << ans << endl;
  }
  return 0;
}
