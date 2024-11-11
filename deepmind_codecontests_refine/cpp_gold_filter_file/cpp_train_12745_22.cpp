#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k, l = 0;
  cin >> n >> p >> k;
  if (p - k > 1) {
    cout << "<< ";
  }
  if (k >= p) {
    l = k - p + 1;
  }
  for (int i = 0; i < k - l; i++) {
    cout << (p - k + l + i) << " ";
  }
  cout << "(" << p << ") ";
  l = 0;
  if (p + k > n) {
    l = p + k - n;
  }
  for (int i = 0; i < k - l; i++) {
    cout << (p + i + 1) << " ";
  }
  if (p + k < n) {
    cout << ">> ";
  }
}
