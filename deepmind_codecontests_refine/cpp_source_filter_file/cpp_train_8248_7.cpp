#include <bits/stdc++.h>
using namespace std;
int t, n, a[1025];
bool b[1025];
bool check(int k, int n) {
  for (int i = 0; i < n; i++)
    if (!b[a[i] ^ k]) return 0;
  return 1;
}
void fn() {
  cin >> n;
  memset(b, false, sizeof(b));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]] = true;
  }
  for (int k = 1; k <= 1024; k++)
    if (check(k, n)) {
      cout << k << endl;
      return;
    }
  cout << -1 << endl;
}
int main() {
  cin >> t;
  while (t--) fn();
  return 0;
}
