#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b[n];
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++) {
    cin >> a;
    b[a] = b[a - 1] + 1;
  }
  cout << n - *max_element(b, b + n);
  return 0;
}
