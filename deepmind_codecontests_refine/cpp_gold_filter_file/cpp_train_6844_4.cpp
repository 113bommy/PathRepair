#include <bits/stdc++.h>
using namespace std;
int x[101];
int main() {
  int n, k, b, cnt = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (x[b] == 0) {
      x[b]++;
      a[cnt] = i;
      cnt++;
    }
  }
  if (cnt < k) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
      cout << a[i] + 1 << " ";
    }
  }
  return 0;
}
