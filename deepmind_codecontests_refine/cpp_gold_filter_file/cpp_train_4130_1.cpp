#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n;
  cin >> n;
  int b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[b[i]] = i + 1;
  }
  int cnt = 0;
  for (int i = 0; i <= 1000; i++) {
    if (a[i] != 0) cnt++;
  }
  cout << cnt << "\n";
  sort(a, a + 1001);
  for (int i = 0; i <= 1001; i++) {
    if (a[i]) cout << b[a[i] - 1] << " ";
  }
  return 0;
}
