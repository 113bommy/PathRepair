#include <bits/stdc++.h>
using namespace std;
int q, k;
int fenq(int first) {
  int p = 1, c = 0, l = 0, cnt = 0;
  while (k > l) {
    k -= l;
    if (++cnt > p) {
      ++c;
      p *= 10;
    }
    l += c;
  }
  int w = 0;
  for (int i = 1; i <= cnt; i++) {
    int j = i;
    long long p = 1;
    while (p * 10 <= j) p *= 10;
    while (p) {
      ++w;
      if (w == k) return j / p % 10;
      p /= 10;
    }
  }
}
int main() {
  cin >> q;
  while (q--) {
    cin >> k;
    cout << fenq(k) << '\n';
  }
}
