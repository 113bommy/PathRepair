#include <bits/stdc++.h>
using namespace std;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, a[123456];
int main() {
  faster();
  int a[100010], n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int i, j, t;
  for (i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      t = i;
      break;
    }
  }
  if (t == n - 1) {
    cout << 0;
    return 0;
  }
  for (j = t + 1; j < n - 1; j++) {
    if (a[j] > a[j + 1]) {
      cout << -1;
      return 0;
    }
  }
  if (a[0] < a[n - 1]) {
    cout << -1;
    return 0;
  }
  cout << n - i - 1;
}
