#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k, k1;
  cin >> n;
  cin >> p;
  cin >> k;
  k1 = k;
  if (p > k) {
    if (p != 1) cout << "<< ";
    for (int i = 0; i < k; i++) {
      cout << p - k1 << " ";
      k1--;
    }
  } else
    for (int i = 1; i < p; i++) cout << i << " ";
  cout << "(" << p << ") ";
  k1 = p + 1;
  if (p < n - k) {
    for (int i = 0; i < k; i++) {
      cout << k1 << " ";
      k1++;
    }
    cout << ">>";
  } else
    for (int i = p + 1; i <= n; i++) cout << i << " ";
}
