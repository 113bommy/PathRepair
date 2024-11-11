#include <bits/stdc++.h>
using namespace std;
int i, n;
long long a[100100];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if ((a[i] - a[0]) * (a[i + 1] - a[i]) < 0) {
      cout << 3 << '\n' << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
      return 0;
    }
  }
  cout << 0;
  return 0;
}
