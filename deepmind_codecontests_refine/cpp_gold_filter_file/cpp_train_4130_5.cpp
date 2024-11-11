#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j] && a[j] != 0) {
        t++;
        a[i] = 0;
      }
    }
  }
  cout << n - t << endl;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  return 0;
}
