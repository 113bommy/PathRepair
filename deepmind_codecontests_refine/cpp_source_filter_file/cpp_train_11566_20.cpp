#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 2];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 1;
  for (int i = 1; i < n; i++)
    if (a[i] > a[i + 1]) cnt++;
  cout << cnt << endl;
  a[n + 1] = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] > a[i + 1]) cout << a[i] << ' ';
  return 0;
}
