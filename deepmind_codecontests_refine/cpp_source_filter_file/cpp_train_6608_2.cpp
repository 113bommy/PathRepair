#include <bits/stdc++.h>
using namespace std;
void read(long long a = 0) {
  freopen("in", "r", stdin);
  if (a) {
    freopen("out", "w", stdout);
  }
}
long long a[5009];
bool is[200000000];
int main() {
  long long n;
  cin >> n;
  long long kl;
  cin >> kl;
  for (int i = 0; i < n; i++) cin >> a[i], is[a[i]] = 1;
  long long q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    long long mi = 100;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < kl; j++)
        for (int k = 1; k + j <= kl; k++) {
          if (x - a[i] * j >= 0 && (x - a[i] * j) % k == 0 &&
              is[(x - a[i] * j) / k])
            mi = min(mi, (long long)k + j);
        }
    }
    if (mi == 100)
      cout << -1;
    else
      cout << mi;
    cout << endl;
  }
}
