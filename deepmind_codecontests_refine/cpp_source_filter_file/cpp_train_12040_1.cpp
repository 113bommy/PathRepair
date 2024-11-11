#include <bits/stdc++.h>
using namespace std;
int ind[10];
int ar[10][1000001];
int f[1000001];
int p(int n) {
  int r = 1;
  while (n) {
    if (n % 10) {
      r *= (n % 10);
    }
    n /= 10;
  }
  return r;
}
int main() {
  for (int i = 1; i <= 9; i++) {
    ind[i] = 1;
    ar[i][0] = i;
    f[i] = i;
  }
  for (int i = 10; i <= 100000; i++) {
    int t = p(i);
    f[i] = f[t];
    ar[f[i]][ind[f[i]]++] = i;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int lo = lower_bound(ar[k], ar[k] + ind[k], l) - ar[k];
    int h = upper_bound(ar[k], ar[k] + ind[k], r) - ar[k];
    h--;
    cout << h - lo + 1 << endl;
  }
  return 0;
}
