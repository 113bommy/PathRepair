#include <bits/stdc++.h>
using namespace std;
long long f[100100], ans[100100], a[100100];
void getv(long long v, long long &cnt, long long t) {
  cnt++;
  if (f[v] == t)
    return;
  else
    getv(f[v], cnt, t);
}
int main() {
  long long T, i;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (i = 1; i <= n; i++) f[i] = i;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      f[i] = a[i];
    }
    for (i = 1; i <= n; i++) {
      long long cnt = 0;
      getv(a[i], cnt, a[i]);
      ans[i] = cnt;
    }
    for (i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
