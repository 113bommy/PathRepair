#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  int a[n];
  long long sum = 0, mn = 10000000, pos = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (mn > abs(a[i])) {
      mn = abs(a[i]);
      pos = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) break;
    a[i] = (-1) * a[i];
    k--;
    if (k == 0) break;
  }
  if (k % 2 == 1) a[pos] = (-1) * a[pos];
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}
