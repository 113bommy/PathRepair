#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int c = 0; c < n; c++) cin >> a[c];
  for (int c = 0; c < n; c++) cin >> b[c];
  int s1 = 0, s2 = 0, M = 0;
  for (int i = 0; i < n; i++) {
    s1 = s2 = 0;
    for (int j = i; j < n; j++) {
      s1 ^= a[j];
      s2 ^= b[j];
      M = max(s1 + s2, M);
    }
  }
  cout << M << endl;
  return 0;
}
