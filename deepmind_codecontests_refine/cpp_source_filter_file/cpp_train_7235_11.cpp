#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, a[200000], c = 1;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i < n; i++) {
    c = c + abs(a[i] - a[i + 1]);
  }
  cout << c;
  return 0;
}
