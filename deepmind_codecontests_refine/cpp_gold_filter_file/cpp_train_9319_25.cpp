#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5);
int n, a[N], b[N];
long long res;
int main() {
  cin >> n;
  long long x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    x = (x | a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    y = (y | b[i]);
  }
  cout << x + y;
  return 0;
}
