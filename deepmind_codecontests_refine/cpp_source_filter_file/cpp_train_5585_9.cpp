#include <bits/stdc++.h>
using namespace std;
struct box {
  int b;
  int a;
};
bool operator<(const box& a, const box& b) {
  if (a.b != b.b) {
    return a.b < b.b;
  } else
    return a.a < b.a;
}
void pri(int x) { cout << x << " "; }
int main() {
  long long n, u, i, j = 0, k = 0, fi = -1, fj = -1, fk = -1;
  cin >> n >> u;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    if ((i > k)) k = i;
    while ((k < (n - 1)) && (a[k + 1] - a[i]) <= u) {
      k++;
    }
    if (k > i) {
      j = i + 1;
      if (fi == -1 || ((a[k] - a[j]) * (a[fk] - a[fi])) >
                          ((a[fk] - a[fj]) * (a[k] - a[i]))) {
        fi = i;
        fj = j;
        fk = k;
      }
    }
  }
  if (fi == -1) {
    cout << -1 << "\n";
  } else {
    cout.precision(15);
    cout << (double)(a[fk] - a[fj]) / (a[fk] - a[fi]) << "\n";
  }
  return 0;
}
