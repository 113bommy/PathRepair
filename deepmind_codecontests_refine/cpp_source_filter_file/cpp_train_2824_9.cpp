#include <bits/stdc++.h>
int n, ms[10000], l;
using namespace std;
int main() {
  cin >> n;
  cin >> l;
  int r(1), max1(1);
  for (int i(0); i < n; i++) {
    cin >> ms[i];
  }
  for (int i(0); i < n - 1; i++) {
    if (ms[i] != ms[i + 1]) {
      r++;
    } else {
      max1 = max(max1, r);
      r = 1;
    }
  }
  max1 = max(max1, r);
  cout << max1;
  return 0;
}
