#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1005];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < a[i - 1] - 1 && a[i] < a[i + 1]) cnt++;
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) cnt++;
  }
  cout << cnt;
  return 0;
}
