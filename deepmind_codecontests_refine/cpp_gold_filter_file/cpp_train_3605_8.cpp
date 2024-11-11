#include <bits/stdc++.h>
using namespace std;
long long n, i, a, s, b[100001];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    s += a;
  }
  for (i = 1; i <= n; i++) cin >> b[i];
  sort(b + 1, b + n + 1);
  if (s <= b[n - 1] + b[n])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
