#include <bits/stdc++.h>
long long mod = 1e9 + 7;
inline long long pwr(long long base, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans = ans * base;
    base = base * base;
    n /= 2;
  }
  return ans;
}
struct range {
  int l, h;
};
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  int mi = 1e9;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  if (ma == mi || ma == mi + 1) {
    cout << n << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
  }
  int fre[3] = {0};
  for (int i = 0; i < n; i++) fre[a[i] - mi]++;
  int mi2 = min(fre[0], fre[2]);
  if (fre[0] + fre[1] + fre[2] - 2 * mi2 <= fre[0] + fre[2] + (fre[1] % 2)) {
    cout << fre[0] + fre[1] + fre[2] - 2 * mi2 << "\n";
    fre[1] += 2 * mi2;
    fre[0] -= mi2;
    fre[2] -= mi2;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < fre[i]; j++) cout << mi + i << " ";
    }
  } else {
    cout << fre[0] + fre[2] + (fre[1] % 2) << "\n";
    fre[0] += fre[1] / 2;
    fre[2] += fre[1] / 2;
    fre[1] %= 2;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < fre[i]; j++) cout << mi + i << " ";
    }
  }
  return 0;
}
