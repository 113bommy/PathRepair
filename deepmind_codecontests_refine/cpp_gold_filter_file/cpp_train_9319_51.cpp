#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[1000], b[1000], l = 0, r = 0, result = 0, lb = 0, rb = 0;
  int n;
  cin >> n;
  for (int c = 0; c < n; c++) {
    cin >> a[c];
  }
  for (int c = 0; c < n; c++) {
    cin >> b[c];
  }
  for (int c = 0; c < n; c++) {
    l |= a[c];
    lb |= b[c];
  }
  result = lb + l;
  cout << result << endl;
  return 0;
}
