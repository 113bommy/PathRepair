#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
long long oddpref[100005];
long long evenpref[100005];
long long evensuff[100005];
long long oddsuff[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    oddpref[i] = oddpref[i - 1];
    evenpref[i] = evenpref[i - 1];
    if (i % 2)
      oddpref[i] += a[i];
    else
      evenpref[i] += a[i];
  }
  for (int i = n; i >= 1; i--) {
    oddsuff[i] = oddsuff[i + 1];
    evensuff[i] = evensuff[i + 1];
    if (i % 2)
      oddsuff[i] += a[i];
    else
      evensuff[i] += a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (oddpref[i - 1] + evensuff[i + 1] == evenpref[i - 1] + oddsuff[i + 1]) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
