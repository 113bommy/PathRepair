#include <bits/stdc++.h>
using namespace std;
const long long NMX = 432000, oo = 0x3C3C3C3C3C3C3C3C, Bs = 1000000007;
long long q, n, a[NMX], A[NMX], kq;
bool dd[NMX], YES;
void update(long long x) {
  while (x > 0) {
    A[x]++;
    x -= ((x) & (-(x)));
  }
}
long long get(long long x) {
  long long res = 0;
  while (x <= n) {
    res += A[x];
    x += ((x) & (-(x)));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= (int)(n); i++) {
      cin >> a[i];
      A[i] = 0;
      dd[i] = false;
    }
    YES = false;
    for (int i = 1; i <= (int)(n); i++) {
      if (dd[a[i]]) {
        cout << "YES\n";
        YES = true;
        break;
      }
      dd[a[i]] = true;
    }
    if (YES) continue;
    kq = 0;
    for (int i = 1; i <= (int)(n); i++) {
      kq += get(a[i] + 1);
      update(a[i]);
    }
    cout << (kq % 2 == 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
