#include <bits/stdc++.h>
using namespace std;
int n, k = 18;
int it[(1 << 20)];
int a[(1 << 20)], b[(1 << 20)], i1[(1 << 20)], i2[(1 << 20)];
int ansi[(1 << 20)];
int sum(int l, int r, int ll = 0, int rr = (1 << k), int ind = 1) {
  if (l <= ll && rr <= r) {
    return it[ind];
  }
  if (rr <= l || r <= ll) {
    return 0;
  }
  return sum(l, r, ll, (ll + rr) / 2, ind * 2) +
         sum(l, r, (ll + rr) / 2, rr, ind * 2 + 1);
}
void add(int x) {
  x += (1 << k);
  for (; x; x /= 2) {
    it[x]++;
  }
}
int getIt(int i, int len = (1 << k - 1), int ind = 1) {
  if (ind >= (1 << k)) {
    return ind - (1 << k);
  }
  if (len - it[ind * 2] <= i) {
    return getIt(i - (len - it[ind * 2]), len / 2, ind * 2 + 1);
  } else {
    return getIt(i, len / 2, ind * 2);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    i1[i] = a[i] - sum(0, a[i]);
    add(a[i]);
  }
  for (int i = 0; i < (1 << k + 1); i++) {
    it[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    i2[i] = b[i] - sum(0, b[i]);
    add(b[i]);
  }
  for (int i = 0; i < (1 << k + 1); i++) {
    it[i] = 0;
  }
  int rem = 0;
  for (int i = n - 2; i >= 0; i--) {
    int maxx = n - i;
    ansi[i] = i1[i] + i2[i] + rem;
    int nr = 0;
    if (ansi[i] >= maxx) {
      ansi[i] -= maxx;
      nr++;
    }
    rem = nr;
  }
  for (int i = 0; i < n; i++) {
    int crr = getIt(ansi[i]);
    add(crr);
    cout << crr << " ";
  }
  cout << "\n";
  return 0;
}
