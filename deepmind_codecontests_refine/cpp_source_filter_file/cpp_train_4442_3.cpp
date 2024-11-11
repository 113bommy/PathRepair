#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int p[1000000] = {0};
  int q[1000000] = {0};
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]]++;
  }
  int sum = 0;
  for (int i = 0; i < m; i++) {
    int h;
    cin >> h;
    q[i + 1] = h;
    sum += h;
  }
  int mi = 0;
  for (int k = 0; k < 1000000; k++) {
    if (q[k] > p[k]) {
      mi = -1;
      break;
    }
  }
  if (mi != -1) {
    int j = n - 1;
    while (j >= 0 && (p[a[j]] > q[a[j]])) {
      p[a[j]]--;
      j--;
    }
    mi = j + 1 - sum;
    for (int i = 0; i < n - m; i++) {
      int r = a[i];
      int o = 0;
      if (p[r] == q[r]) {
        j++;
        while (j < n && a[j] != r) {
          p[a[j]]++;
          j++;
        }
        if (j == n) {
          o = -1;
          break;
        }
      } else
        p[r]--;
      if (o != -1) mi = min(mi, j - i - sum);
    }
  }
  cout << mi << endl;
  return 0;
}
