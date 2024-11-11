#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int c = 0, c2 = 0, c3 = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] > a[i]) c2++;
    if (b[i] < a[i]) c++;
    if (b[i] == a[i]) c3++;
  }
  if (c3 == n) {
    cout << -1;
    return 0;
  }
  if (c2 == 0) {
    cout << 1;
    return 0;
  }
  if (c == c2) {
    cout << -1;
    return 0;
  }
  if (c == 0) {
    cout << -1;
    return 0;
  }
  if (c2 % c == 0) {
    cout << c2 / c + 1;
  } else
    cout << c2 / c + 1;
}
