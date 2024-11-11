#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010100], b[1010100];
void GoHome() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  cin >> m;
  for (int i = (1); i <= (m); ++i) cin >> b[i];
  int i = 1, j = 1;
  int cnt = 0;
  long long suma = 0, sumb = 0;
  while (i <= n && j <= m) {
    if (suma <= sumb) {
      suma += a[i++];
    } else
      sumb += b[j++];
    if (suma == sumb) {
      cnt++;
      suma = sumb = 0;
    }
  }
  while (i <= n) {
    suma += a[i++];
  }
  while (j <= m) {
    sumb += b[j++];
  }
  if (suma == sumb)
    cout << cnt + 1;
  else
    cout << -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  GoHome();
}
