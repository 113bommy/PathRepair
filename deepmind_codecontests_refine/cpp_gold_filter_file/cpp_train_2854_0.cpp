#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 2;
  cin >> n;
  long long a[n + 1];
  int c = 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < n; i++) {
    if (a[i] == a[i - 1] + a[i - 2]) {
      c++;
      m = max(m, c);
    } else
      c = 2;
  }
  if (n > 2)
    cout << m;
  else
    cout << n;
}
