#include <bits/stdc++.h>
using namespace std;
int n, i, v[100010], t, k, a[100010], minim, poz;
int main() {
  cin >> n >> k;
  minim = 999999999;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
    t = i % k;
    if (!t) t = k;
    a[t] += v[i];
  }
  for (i = 1; i <= k; i++) {
    if (a[i] < minim) {
      minim = a[i];
      poz = i;
    }
  }
  cout << poz;
}
