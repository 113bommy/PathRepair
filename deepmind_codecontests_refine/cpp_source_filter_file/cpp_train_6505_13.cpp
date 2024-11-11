#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 5;
int n, m, a[MAXN], b[MAXN];
long long sum = 0;
bool check(long long time) {
  for (int i = 0; i < n; i++) b[i] = a[i];
  long long t = 0;
  int j = 0;
  for (int i = 0; i < m; i++) {
    long long ttime = time - j - 1;
    while (ttime > 0 && j < n) {
      int c = min(b[j] * 1LL, ttime);
      b[j] -= c;
      ttime -= c;
      t += c;
      if (b[j] == 0) {
        j++;
        ttime--;
      }
    }
  }
  return t >= sum;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long l = 0, r = 1LL * 100 * 1000 * 1000 * 1000;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}
