#include <bits/stdc++.h>
using namespace std;
long long n, m, op, sum;
long long a[1000005], b[1000005], gp[1000005];
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) cin >> a[i], sum += a[i], b[i] = sum % n;
  b[m] = n;
  sort(b + 1, b + 1 + m);
  cout << (ceil(sum * 1.0 / n)) << endl;
  for (int i = 1; i <= m; i++) gp[i] = b[i] - b[i - 1];
  for (int i = 1; i <= m; i++) cout << gp[i] << " ";
  cout << endl;
  for (int i = 1, pos = 1; i <= m; i++) {
    while (a[i] > 0) {
      a[i] -= gp[pos++];
      cout << i;
      if (pos == m + 1)
        cout << endl, pos = 1;
      else
        cout << " ";
    }
    if (i == m)
      if (pos != 1)
        while (pos != m + 1) cout << 1 << " ", pos++;
  }
  cout << endl;
}
