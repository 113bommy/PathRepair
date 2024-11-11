#include <bits/stdc++.h>
using namespace std;
int v[100001], h[100005], d[100005];
int main() {
  int n, i;
  cin >> n;
  int cnt = 2;
  for (i = 1; i <= n; i++) {
    cin >> v[i] >> h[i];
  }
  for (i = 2; i <= n; i++) {
    d[i] = v[i] - v[i - 1];
  }
  for (i = 1; i < n; i++) {
    if (h[i] < d[i]) {
      cnt++;
    } else if (h[i] >= d[i] && h[i] < d[i + 1]) {
      cnt++;
      d[i + 1] -= h[i];
    }
  }
  if (n == 1) {
    cout << "1";
    return 0;
  } else
    cout << cnt;
  return 0;
}
