#include <bits/stdc++.h>
using namespace std;
const long double m = 0.000001;
long long n, i, p, a[100001], b[100001];
long double l, h, mid, k;
bool Check(long double x) {
  k = 0;
  for (i = 1; i <= n; i++)
    if (x * a[i] - b[i] > 0) k += (x * a[i] - b[i]);
  if (k > x * p) return false;
  return true;
}
void Init() {
  cin >> n >> p;
  for (i = 1; i <= n; i++) cin >> a[i] >> b[i];
  l = 0;
  h = 1e12;
  if (Check(1e13)) {
    cout << -1;
    return;
  }
  while (l <= h) {
    mid = (l + h) / 2;
    if (Check(mid))
      l = mid + m;
    else
      h = mid - m;
  }
  cout << h;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  Init();
}
