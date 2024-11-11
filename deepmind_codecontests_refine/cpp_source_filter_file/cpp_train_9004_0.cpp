#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int* l = new int[n + 1]();
  int* r = new int[n + 1]();
  int* c = new int[n + 1]();
  int* td = new int[n + 1];
  int* d = new int[n + 1];
  int maxh = 0, maxi;
  for (int i = 0; i < n; i++) {
    cin >> td[i];
    if (td[i] > maxh) {
      maxh = td[i];
      maxi = i;
    }
  }
  for (int i = 0; i < n; i++) {
    d[i] = td[(i + maxi) % n];
  }
  d[n] = maxh;
  c[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    r[i] = i + 1;
    while (r[i] < n && d[i] > d[r[i]]) r[i] = r[r[i]];
    if (r[i] < n && d[i] == d[r[i]]) {
      c[i] = c[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  for (int i = 1; i <= n; ++i) {
    l[i] = i - 1;
    while (l[i] >= 0 && d[i] > d[l[i]]) l[i] = l[l[i]];
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += c[i];
    ans += 2;
    if (l[i] == 0 && r[i] == n) ans--;
  }
  cout << ans << endl;
  return 0;
}
