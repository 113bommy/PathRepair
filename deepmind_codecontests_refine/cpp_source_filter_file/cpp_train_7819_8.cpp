#include <bits/stdc++.h>
using namespace std;
int main() {
  long long price = 0;
  int n, m, k, ch[200010], l, r[200010], MAX;
  cin >> n;
  MAX = 0;
  for (int i = 0; i < n; ++i) {
    cin >> ch[i];
    k = 0;
    for (int j = 0; j < ch[i]; ++j) {
      cin >> l;
      if (l > k) {
        k = l;
      }
    }
    if (k > MAX) {
      MAX = k;
    }
    r[i] = k;
  }
  for (int i = 0; i < n; ++i) {
    price += ch[i] * (MAX - r[i]);
  }
  cout << price;
  return 0;
}
