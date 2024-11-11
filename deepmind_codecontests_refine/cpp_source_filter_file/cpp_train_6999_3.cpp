#include <bits/stdc++.h>
using namespace std;
long long a1[500000];
long long b1[500000];
long long c1[500000];
unsigned long long ff(long long x, long long y, long long z) {
  return (unsigned long long)((x - y) * (x - y) + (y - z) * (y - z) +
                              (x - z) * (x - z));
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < a; i++) cin >> a1[i];
    sort(a1, a1 + a);
    for (int i = 0; i < b; i++) {
      cin >> b1[i];
    }
    sort(b1, b1 + b);
    for (int i = 0; i < c; i++) {
      cin >> c1[i];
    }
    sort(c1, c1 + c);
    unsigned long long sum = 1e19 + 10;
    int ans = 0;
    for (int i = 0; i < a; i++) {
      long long k1 = upper_bound(b1, b1 + b, a1[i]) - b1;
      long long k2 = upper_bound(c1, c1 + c, a1[i]) - c1;
      if (k1 < b) {
        if (k2 < c) sum = min(sum, ff(a1[i], b1[k1], c1[k2]));
        if (k2 > 0) sum = min(sum, ff(a1[i], b1[k1], c1[k2 - 1]));
      }
      if (k1 > 0) {
        if (k2 < c) sum = min(sum, ff(a1[i], b1[k1 - 1], c1[k2]));
        if (k2 > 0) {
          sum = min(sum, ff(a1[i], b1[k1 - 1], c1[k2 - 1]));
        }
      }
    }
    for (int i = 0; i < b; i++) {
      long long k1 = upper_bound(a1, a1 + b, b1[i]) - a1;
      long long k2 = upper_bound(c1, c1 + c, b1[i]) - c1;
      if (k1 < a) {
        if (k2 < c) sum = min(sum, ff(b1[i], a1[k1], c1[k2]));
        if (k2 > 0) sum = min(sum, ff(b1[i], a1[k1], c1[k2 - 1]));
      }
      if (k1 > 0) {
        if (k2 < c) sum = min(sum, ff(b1[i], a1[k1 - 1], c1[k2]));
        if (k2 > 0) sum = min(sum, ff(b1[i], a1[k1 - 1], c1[k2 - 1]));
      }
    }
    for (int i = 0; i < c; i++) {
      long long k1 = upper_bound(b1, b1 + b, c1[i]) - b1;
      long long k2 = upper_bound(a1, a1 + a, c1[i]) - a1;
      if (k1 < b) {
        if (k2 < a) sum = min(sum, ff(c1[i], b1[k1], a1[k2]));
        if (k2 > 0) sum = min(sum, ff(c1[i], b1[k1], a1[k2 - 1]));
      }
      if (k1 > 0) {
        if (k2 < a) sum = min(sum, ff(c1[i], b1[k1 - 1], a1[k2]));
        if (k2 > 0) sum = min(sum, ff(c1[i], b1[k1 - 1], a1[k2 - 1]));
      }
    }
    cout << sum << "\n";
  }
}
