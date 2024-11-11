#include <bits/stdc++.h>
using namespace std;
long long a[3005], b[3005], c[3005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c[j] += abs(a[i] - b[j]);
      if (j > 1) c[j] = min(c[j - 1], c[j]);
    }
  }
  cout << c[n] << endl;
  return 0;
}
