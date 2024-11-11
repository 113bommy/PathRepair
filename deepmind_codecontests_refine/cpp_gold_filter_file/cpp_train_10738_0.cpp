#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
long long a[200005];
bool used[200005];
int main() {
  scanf("%d %lld", &n, &z);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    used[i] = false;
  }
  sort(a, a + n);
  int cnt = 0;
  int m = n / 2;
  for (int i = 0; i < n / 2; i++) {
    if (used[i]) continue;
    if (a[n - 1] - a[i] < z) break;
    for (; m < n; m++) {
      if (a[m] - a[i] >= z) {
        cnt++;
        used[m] = true;
        break;
      }
    }
    if (m == n) break;
    m++;
  }
  cout << cnt << endl;
  return 0;
}
