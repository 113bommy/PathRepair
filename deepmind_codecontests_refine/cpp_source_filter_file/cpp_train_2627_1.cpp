#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  a[0] = b[0];
  long long m = a[0];
  for (int i = 1; i < n; i++) {
    if (b[i] == 0)
      a[i] = b[i];
    else if (b[i] > 0) {
      a[i] = m + b[i];
      m += b[i];
    } else {
      a[i] = b[i] + m;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
