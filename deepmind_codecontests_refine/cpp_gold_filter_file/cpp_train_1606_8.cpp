#include <bits/stdc++.h>
using namespace std;
struct ptu {
  long val;
  long index;
};
bool func(ptu a, ptu b) { return a.val < b.val; }
ptu *a;
long n;
long d1, d2;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  a = new ptu[2 * n];
  for (long i = 0; i < n; i++) {
    cin >> a[i].val >> a[i + n].val;
    a[i].index = i;
    a[i + n].index = i + n;
  }
  sort(a + 0, a + 2 * n, func);
  d1 = -1;
  d2 = -1;
  for (long i = n - 1; i >= 0; i--) {
    long x = a[i].index;
    if ((x < n) && (d1 == -1)) d1 = x;
    if ((x >= n) && (d2 == -1)) d2 = x - n;
    if ((d1 != -1) && (d2 != -1)) break;
  }
  if (d1 < n / 2 - 1) d1 = n / 2 - 1;
  if (d2 < n / 2 - 1) d2 = n / 2 - 1;
  for (long i = 0; i <= d1; i++) {
    cout << 1;
  }
  for (long i = d1 + 1; i < n; i++) {
    cout << 0;
  }
  cout << endl;
  for (long i = 0; i <= d2; i++) {
    cout << 1;
  }
  for (long i = d2 + 1; i < n; i++) {
    cout << 0;
  }
  delete[] a;
}
