#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[105], b[105], cnt = 0, vis = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        a[j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      cnt++;
      b[vis++] = i;
    }
  }
  if (cnt == k) {
    cout << "YES" << endl;
    for (int i = 0; i < vis; i++) cout << b[i] + 1 << " ";
  } else
    cout << "NO";
  return 0;
}
